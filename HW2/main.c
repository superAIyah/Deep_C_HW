/* 100 мб = 1e+8 б
1e+8 / sizeof(__int32_t) = 1e8 / 4 = 25e+6
*/

#include "dist_no_parallel.h"
#include <stdio.h>

int main()
{
    srand(time(0));
    int* mas = create_mas(SZ);
    double dist = count_sum_dist(mas, SZ);
    printf("%f\n", dist);
}