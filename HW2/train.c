#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int cpu = sysconf(_SC_NPROCESSORS_ONLN);
    printf("CPU = %d\n", cpu);

    int mas[100];
    for (int i = 0; i < 100; i++)
        mas[i] = i;
    
    int N = 100;
    int p = 10;
    int step = N / p;
    int i = 0;
    int cnt = 0;

    int fd[p][2];
    // fd[i][0] - reading
    // fd[i][1] - writing

    while (i < 100) {
        pipe(fd[cnt]);
        pid_t child = fork();
        if (child == 0) {  // зашли в этого ребенка
            int me = getpid();
            int end = i + 10;
            double sum = 0;
            for (int j = i; j < end; j++) {
                sum += j;
            }
            
            // pipe
            close(fd[cnt][0]); // nothing to read
            write(fd[cnt][1], &sum, sizeof(sum));
            close(fd[cnt][1]);

            printf("sum from %d to %d = %f\n", i, end, sum);

            exit(0);
        }
        i += step;
        cnt++;
    }
    double sum = 0;
    for (int i = 0; i < p; i++) {
        double sumFromChild;
        close(fd[i][1]); // norhing to write
        read(fd[i][0], &sumFromChild, sizeof(sumFromChild));
        sum += sumFromChild;
        printf("i = %d, SUM = %f\n", i, sum);
    }
    return 0;
}