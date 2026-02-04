#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double sbase = 1.5;
double sone_bit = 0.5;
double shift = 0.25;
int k;
int m;
double x;
double _usr_y1;
double y2;
float *xflt;
double *xdbl;
double *ydbl;

#define y1 _usr_y1

void init_vars() {
    const int size = 16777216; // ~128 MB of total data (adjustable)
    xdbl = (double*)aligned_alloc(32, size * sizeof(double));
    ydbl = (double*)aligned_alloc(32, size * sizeof(double));
    xflt = (float*)aligned_alloc(32, 2 * size * sizeof(float));

    for (int i = 0; i < size; ++i) {
        xdbl[i] = (double)(i % 1000) * 0.01;
        ydbl[i] = (double)((i + 500) % 1000) * 0.01;
    }

    sbase = 1.5;
    sone_bit = 0.5;
    shift = 0.25;
}