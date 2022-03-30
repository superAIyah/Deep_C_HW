#include <gtest/gtest.h>

extern "C" {
    #include <stdio.h>
    #include "dist_no_parallel.h"
    #include "dist_parallel.h"
    #include <dlfcn.h>
}

//cd build/
//lcov -t "tests/test_libs" -o coverage.info -c -d static_lib/ -d dynamic_lib/
//genhtml -o report coverage.info
//cd report
//python3 -m http.server 8000

TEST(answers, big_test) {
    int cpu = sysconf(_SC_NPROCESSORS_ONLN);  // количество процессоров

    int n = 1000000; // заполняем массив
    int32_t mas[n];
    for (int i = 0; i < n; i++)
        mas[i] = i%100;

    double result1 = count_sum_dist(mas, n);
    double result2 = count_sum_dist_parallel(mas, n, cpu);
    EXPECT_EQ(result1, result2);
}

TEST(answers, too_many_proceses) {
    int cpu = sysconf(_SC_NPROCESSORS_ONLN);  // количество процессоров

    int n = 6; // заполняем массив
    int32_t mas[n];
    for (int i = 0; i < n; i++)
        mas[i] = i%100;

    double result1 = count_sum_dist(mas, n);
    double result2 = count_sum_dist_parallel(mas, n, cpu);
    EXPECT_EQ(result1, result2);
}

TEST(min_max, correct_sum) {
    int n = 10;
    int32_t mas[n];
    for (int i = 0; i < n; i++)
        mas[i] = i%100;
    
    double result1 = count_sum_dist_parallel(mas, n, n);  // n процессов
    double result2 = count_sum_dist_parallel(mas, n, 1);  // 1 процесс
    EXPECT_EQ(result1, result2);
}

TEST(stress_test, fork_fail) {
    int n = 100000;
    int32_t mas[n];
    for (int i = 0; i < n; i++)
        mas[i] = i%100;

    double result1 = count_sum_dist_parallel(mas, n, n);  // слишком много процессов
    EXPECT_EQ(result1, -1);
}