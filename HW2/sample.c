/* 100 мб = 1e+8 б
1e+8 / sizeof(__int32_t) = 1e8 / 4 = 25e+6 -> 1e6 (примерно)
*/

#include <stdio.h>
#include <stdlib.h>
#include "dist_no_parallel.h"
#include "dist_parallel.h"
#include <dlfcn.h>
#include <sys/time.h>

int main(int argc, char* argv[])
{
    int cpu = sysconf(_SC_NPROCESSORS_ONLN);  // количество процессоров
    printf("cpu = %d = num of processes\n", cpu);

    int n = 26214400; // заполняем массив
    int32_t* mas;
    mas = malloc(4 * n); 
    for (int i = 0; i < n; i++)
        mas[i] = i % 100;
    
    double res_parallel = count_sum_dist_parallel(mas, n, cpu); // simple test output
    double res_no_parallel = count_sum_dist(mas, n);

    printf("parallel result is %f\n", res_parallel);
    printf("NO parallel result is %f\n", res_no_parallel);
    free(mas);
    return 0;
}