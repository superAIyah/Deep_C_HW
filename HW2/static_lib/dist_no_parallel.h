/* 100 мб = 1e+8 б
1e+8 / sizeof(__int32_t) = 1e8 / 4 = 25e+6 = SZ
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

#define SZ 25e6

#ifndef Point
#define Point

typedef struct Point2 {
    int8_t x1;
    int8_t y1;
    int8_t x2;
    int8_t y2;
} Point2;

#endif

static void fill_bits(int32_t* a);  // заполнить число случайными битами
int32_t* create_mas(int sz);  // создаем массив с точками
static Point2 get_point(int32_t a);  // прочитать из int32 4 числа int8
static float dist(Point2 p);  // дистанция между (x1, y1) и (x2, y2)
double count_sum_dist(int32_t* mas, int sz);  // посчитать суммарный путь по точкам в массиве
void debug(Point2 a);  // вывести точку
