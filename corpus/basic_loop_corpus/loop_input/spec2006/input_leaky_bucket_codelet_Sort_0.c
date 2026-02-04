#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

unsigned long NumberLeakyBuckets = 1 << 14; // 16384 elements
unsigned long *Rmin;
unsigned long i;
unsigned long j;
unsigned long temp;

void init_vars() {
    Rmin = (unsigned long *)malloc(NumberLeakyBuckets * sizeof(unsigned long));
    srand((unsigned int)time(NULL));
    for (unsigned long idx = 0; idx < NumberLeakyBuckets; idx++) {
        Rmin[idx] = rand() % 1000000;
    }
}