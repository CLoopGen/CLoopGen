#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * (1 << 20) / sizeof(double))

double dd[ARRAY_SIZE];
double xa[ARRAY_SIZE];
size_t size = ARRAY_SIZE;
double x = 3.14159;
size_t i;
double y = 1.0;

void init_vars() {
    srand(time(NULL));
    for (size_t idx = 0; idx < size; ++idx) {
        dd[idx] = ((double)rand() / RAND_MAX) * 2.0 - 1.0;
        xa[idx] = ((double)rand() / RAND_MAX) * 10.0;
    }
    y = 1.0;
    i = 0;
}