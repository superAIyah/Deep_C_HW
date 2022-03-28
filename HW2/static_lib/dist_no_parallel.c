#include "dist_no_parallel.h"

static void fill_bits(int32_t* a) { // заполнить число случайными битами
    for (int i = 0; i < 32; i++) {
        int rand_0_1 = rand() % 2;
        *a = *a | (rand_0_1 << i);
    }
}

static int32_t* create_mas(int sz) {  // создаем массив с точками
    int32_t* mas = malloc(sizeof(int32_t) * sz);
    for (int i = 0; i < sz; i++) {
        mas[i] = 0;
        fill_bits(&mas[i]);  // случайно флипаем биты в числе
    }
    return mas;
}

static Point2 get_point(int32_t a) {  // прочитать из int32 4 числа int8
    int8_t* mas = malloc(sizeof(int8_t) * 4);
    for (int i = 0; i < 4; i++) {
        int8_t tmp = 0;
        for (int j = 0; j < 8; j++) {
            int bit = a & 1;  // считаем младший бит
            tmp = tmp | (bit << j); // присвоем его текущему числу
            a = a >> 1;  // сдвинем число вправо на 1 бит
        }
        mas[i] = tmp;
    }
    Point2 result = {mas[0], mas[1], mas[2], mas[3]};
    free(mas);
    return result;
}

static float dist(Point2 p) {  // дистанция между (x1, y1) и (x2, y2)
    return sqrt(pow(p.x2 - p.x1, 2) + pow(p.y2 - p.y1, 2));
}

double count_sum_dist(int32_t* mas, int sz) {  //посчитать суммарный путь по точкам в массиве
    double sum = 0;
    for (int i = 0; i < sz - 1; i++) {
        Point2 now = get_point(mas[i]);
        Point2 next = get_point(mas[i + 1]);
        sum += dist(now);  // расстояние отрезка
        Point2 between = {now.x2, now.y2, next.x1, next.y1};
        sum += dist(between);  // расстояние до следующего отрезка
    }
    Point2 lastest = get_point(mas[sz - 1]); // расстояние последнего отрезка
    sum += dist(lastest);
    return sum;
}

static void debug(Point2 a) {
    printf("%d %d\n", a.x1, a.y1);
    printf("%d %d\n", a.x2, a.y2);
}