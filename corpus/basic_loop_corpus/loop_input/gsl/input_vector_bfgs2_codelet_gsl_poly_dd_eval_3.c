#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define ARRAY_SIZE (DATA_SIZE_MB * (1 << 20) / sizeof(double))

double dd[ARRAY_SIZE];
double xa[ARRAY_SIZE];
size_t size = ARRAY_SIZE;
double x = 1.5;
size_t i;
double y;

void init_vars() {
    for (size_t idx = 0; idx < size; idx++) {
        dd[idx] = idx * 0.5;
        xa[idx] = idx * 0.1;
    }
    y = 0.0;
}