/* 100 мб = 1e+8 б
1e+8 / sizeof(__int32_t) = 1e8 / 4 = 25e+6
*/

#include <stdio.h>
#include "dist_no_parallel.h"
#include "dist_parallel.h"
#include <dlfcn.h>

int main()
{
    int n = 10000;
    int32_t mas[n];
    for (int i = 0; i < n; i++)
        mas[i] = i;
    double dist1 = count_sum_dist(mas, n);
    int proc = 2;
    double dist2 = count_sum_dist_parallel(mas, n, proc);
    printf("dist1 ususal = %f\n", dist1);
    printf("dist1 parallel = %f\n", dist2);
}