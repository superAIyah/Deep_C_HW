#include "dist_parallel.h"

Point2 get_point(int32_t a) {  // прочитать из int32 4 числа int8
    Point2 result;
    for (int i = 0; i < 4; ++i) {  // считываем x1, y1, x2, y2
        int8_t tmp = 0;
        for (int j = 0; j < 8; ++j) {
            int bit = a & 1;  // считаем младший бит
            tmp |= (bit << j); // присвоем его текущему числу
            a >>= 1;  // сдвинем число вправо на 1 бит
        }
        switch (i)
        {
        case 0:
            result.x1 = tmp;
            break;
        case 1:
            result.y1 = tmp;
            break;
        case 2:
            result.x2 = tmp;
            break;
        case 3:
            result.y2 = tmp;
            break;
        }
    }
    return result;
}

static float dist(Point2 p) {  // дистанция между (x1, y1) и (x2, y2)
    return sqrt(pow(p.x2 - p.x1, 2) + pow(p.y2 - p.y1, 2));
}

static double count_segment(int32_t* mas, int left, int right) {
    double sum = 0; // сумма расстояние от точки mas[left](x1, y1) до mas[right](x1, y1)
    for (int i = left; i < right; i++) {
        Point2 now = get_point(mas[i]);
        Point2 next = get_point(mas[i + 1]);
        sum += dist(now);  // расстояние отрезка
        Point2 between = {now.x2, now.y2, next.x1, next.y1};
        sum += dist(between);  // расстояние до следующего отрезка
    }
    return sum;
}

double count_sum_dist_parallel(int32_t* mas, int sz, int num_proc) {  //посчитать суммарный путь по точкам в массиве
    if (num_proc > sz) {  // слишком много процессов на массив
        num_proc = sz;
    }

    int step = sz / num_proc;  // количество элементов на процесс
    int fd[num_proc][2];  // pipe
    // fd[i][0] - reading
    // fd[i][1] - writing
    int cnt = 0;  // index of current pipe
    int index = 0;  // индекс элемента в массиве
    int error_flag = 0;  // если кончились процессы -> закрыть все открытые -> вернуть ошибку

    while (index != sz - 1) { 
        pipe(fd[cnt]);
        pid_t child = fork();
        if (child == -1) {
            error_flag = 1;
            close(fd[cnt][0]);
            close(fd[cnt][1]);
            break;  // конец обработки массива, возврат ошибки
        }
        int start = index;  // посчитаем границы подсчета для ребенка
        int end = start + step;
        if (cnt == num_proc - 1) {  // последний поток досчитывает остаток
            end = sz - 1;
        }
        if (child == 0) {  // мы внутри ребенка
            close(fd[cnt][0]);  // nothing to read
            double sumi = count_segment(mas, start, end);
            write(fd[cnt][1], &sumi, sizeof(sumi));  // writing
            close(fd[cnt][1]);
            exit(0);
        }
        index = end;
        cnt++;
    }

    pid_t pid;
    while ( (pid = waitpid(-1, NULL, WNOHANG)) > 0) { }// дожидаемся закрытия всех процессов

    if (error_flag) {
        for (int i = 0; i < cnt; i++) {
            close(fd[i][0]);  // закрываем потоки которые успели открыть
            close(fd[i][1]);
        }
        return ERROR;
    }

    // считываем суммы потоков
    double all_sum = 0;
    for (int i = 0; i < cnt; i++) {
        double sum_child;
        close(fd[i][1]);  // закрываем конец на запись
        read(fd[i][0], &sum_child, sizeof(sum_child));
        close(fd[i][0]);
        all_sum += sum_child;
    }
    all_sum += dist(get_point(mas[sz - 1]));  // добавляем расстоние последнего отрезка
    return all_sum;
}