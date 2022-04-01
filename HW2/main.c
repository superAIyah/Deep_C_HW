/* 100 мб = 1e+8 б
1e+8 / sizeof(__int32_t) = 1e8 / 4 = 25e+6 -> 1e6 (примерно)
*/

#include <stdio.h>
#include <stdlib.h>
#include "dist_no_parallel.h"
#include "dist_parallel.h"
#include <dlfcn.h>
#include <sys/time.h>

double get_time(int* mas, int sz, int times, int num_proc) {
    struct timespec start, finish;
    double elapsed = 0;
    for (int i = 0; i < times; i++) {
        clock_gettime(CLOCK_REALTIME, &start);
        if (num_proc != 0){
            count_sum_dist_parallel(mas, sz, num_proc);  // параллельная сумма
        }
        else {
            count_sum_dist(mas, sz);  // без мультипроцессинга
        }
        clock_gettime(CLOCK_REALTIME, &finish);
        elapsed += (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    }
    elapsed /= times;
    return elapsed;
}

int main(int argc, char* argv[])
{
    int times = 3;  // сколько раз считать время перед усреднением
    int n = 26214400;//26214400; // заполняем массив
    int32_t* mas;
    mas = malloc(104857600);  // 26214400 * 4 
    for (int i = 0; i < n; i++)
        mas[i] = i % 100;

    // сравнительный анализ
    double time_best = 100;
    int num_proc_best = -1;
    int cnt_measure = 10;
    int step = 8;
    double parallel_times[cnt_measure];
    double no_parallel_times[cnt_measure];
    for (int i = 0; i < cnt_measure; i++) {
        printf("i = %d\n", i);
        int cnt_proc = 1 + i * step;
        double parallel = get_time(mas, n, times, cnt_proc);
        double non_parallel = get_time(mas, n, times, 0);
        parallel_times[i] = parallel;
        no_parallel_times[i] = non_parallel;
        if (parallel < time_best) {
            time_best = parallel;
            num_proc_best = cnt_proc;
        }
    }

    FILE* fp = fopen("time.txt", "w");
    if (fp == NULL) {
        printf("Can not open file\n");
        return 0;
    }
    // вывод таблицы
    char const* col0 = "number of process";
    char const* col1 = "parallel time";
    char const* col2 = "non parallel time";
    fprintf(fp, "\nResearch table: \n");
    fprintf(fp, "%-20s|%-20s|%-20s\n", col0, col1, col2);
    for (int i = 0; i < cnt_measure; i++) {
        fprintf(fp, "%-20d|%-20f|%-20f\n", 1 + (step * i), parallel_times[i], no_parallel_times[i]);
    }
    fprintf(fp, "BEST TIME IS %f WITH %d PROCESSES\n", time_best, num_proc_best);
    fclose(fp);
    return 0;
}