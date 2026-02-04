#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double dd[1 << 20];
double xa[1 << 20];
size_t size = 1 << 20;
double x = 1.5;
size_t i;
double y = 0.0;

void init_vars() {
    size = 1 << 20;
    x = 1.5;
    y = 0.0;
    for (size_t idx = 0; idx < size; idx++) {
        xa[idx] = (double)(idx + 1) / (double)size;
        dd[idx] = 1.0 / (1.0 + idx);
    }
}