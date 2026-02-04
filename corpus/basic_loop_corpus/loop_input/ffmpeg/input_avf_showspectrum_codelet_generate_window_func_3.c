#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *lut;
int N = 1 << 20;
int n;
double b;
double sum;
double t;
double c;
double norm = 0.0;
int j;

void init_vars() {
    lut = (float*)aligned_alloc(32, N * sizeof(float));
    if (!lut) {
        exit(1);
    }
    for (int i = 0; i < N; ++i) {
        lut[i] = 0.0f;
    }
    b = sqrt(2.0);
}