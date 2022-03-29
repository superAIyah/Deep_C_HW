// crt_clock.c
// This sample uses clock() to 'sleep' for three
// seconds, then determines how long it takes
// to execute an empty loop 600000000 times.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void fill_bits(int32_t* a) { // заполнить число случайными битами
    for (int i = 0; i < 32; i++) {
        int rand_0_1 = rand() % 2;
        *a = *a | (rand_0_1 << i);
    }
}

int32_t* create_mas(int sz) {  // создаем массив с точками
    int32_t* mas = malloc(sizeof(int32_t) * sz);
    for (int i = 0; i < sz; i++) {
        mas[i] = 0;
        fill_bits(&mas[i]);  // случайно флипаем биты в числе
    }
    return mas;
}

// Pauses for a specified number of clock cycles.
void do_sleep( clock_t wait )
{
   clock_t goal;
   goal = wait + clock();
   while( goal > clock() )
      ;
}

void debug(Point2 a) {
    printf("%d %d\n", a.x1, a.y1);
    printf("%d %d\n", a.x2, a.y2);
}

const long num_loops = 600000000L;

int main( void )
{
   long    i = num_loops;
   clock_t start, finish;
   double  duration;

   // Delay for a specified time.
   printf( "Delay for three seconds\n" );
   do_sleep( (clock_t)3 * CLOCKS_PER_SEC );
   printf( "Done!\n" );

   // Measure the duration of an event.
   start = clock();
   while( i-- )
      ;
   finish = clock();
   duration = (double)(finish - start) / CLOCKS_PER_SEC;
   printf( "Time to do %ld empty loops is ", num_loops );
   printf( "%2.3f seconds\n", duration );
}