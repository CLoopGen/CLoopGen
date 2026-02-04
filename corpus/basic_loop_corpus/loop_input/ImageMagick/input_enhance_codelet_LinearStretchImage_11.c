#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double white_point;
double *histogram;
double intensity;
ssize_t white;

void init_vars() {
    white_point = 1e9;
    intensity = 0.0;
    histogram = (double*)aligned_alloc(32, (65536) * sizeof(double));
    
    if (!histogram) exit(1);
    
    for (size_t i = 1; i <= 65535; i++) {
        histogram[i] = (double)(rand() % 100000);
    }
    histogram[0] = 0.0;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}