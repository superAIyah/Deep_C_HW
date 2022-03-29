/* 100 мб = 1e+8 б
1e+8 / sizeof(__int32_t) = 1e8 / 4 = 25e+6 -> 1e6 (примерно)
*/

#include <stdio.h>
#include "dist_no_parallel.h"
#include "dist_parallel.h"
#include <dlfcn.h>
#include <time.h>

typedef struct time_result {
    double ans;
    double time;
} time_result;

time_result get_time(int* mas, int sz, int times, int num_proc) {
    clock_t start_t, end_t;
    double total = 0;
    double ans;
    for (int i = 0; i < times; i++) {
        start_t = clock();
        if (num_proc != 0){
            ans = count_sum_dist_parallel(mas, sz, num_proc);
        }
        else {
            ans = count_sum_dist(mas, sz);
        }
        end_t = clock();
        total += (end_t - start_t) / (double)CLOCKS_PER_SEC;
    }
    total /= times;
    time_result result = {ans, total};
    return result;
}

void show_time(time_result a) {
    printf("result = %f | time = %f\n", a.ans, a.time);
}

int main()
{
    int times = 5;  // количество раз по которым усреднять время работы
    int cpu = sysconf(_SC_NPROCESSORS_ONLN);  // количество процессоров
    printf("cpu = %d\n", cpu);

    int n = 1000000; // заполняем массив
    int32_t mas[n];
    for (int i = 0; i < n; i++)
        mas[i] = i;

    time_result a = get_time(mas, n, 5, 8);
    time_result b = get_time(mas, n, 5, 0);

    show_time(a);
    show_time(b);
}