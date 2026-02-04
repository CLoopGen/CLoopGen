#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *lut;
int N;
int n;
double b;
double sum;
double t;
double c;
double norm;
int j;

void init_vars() {
    N = 1 << 20;
    lut = (float*)aligned_alloc(32, N * sizeof(float));
    if (!lut) exit(1);
    for (int i = 0; i < N; ++i) {
        lut[i] = 0.0f;
    }
    b = 2.0;
    norm = 0.0;
}