#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

#define DATA_SIZE_MB 64
#define TOTAL_FLOATS ((DATA_SIZE_MB * (1 << 20)) / sizeof(float))

int N;
void *X;
int incX;
void *Y;
int incY;
float r_real;
float r_imag;
int i;
int ix;
int iy;

void init_vars() {
    N = TOTAL_FLOATS / 4; 
    if (N == 0) N = 1;

    X = aligned_alloc(32, TOTAL_FLOATS * sizeof(float));
    Y = aligned_alloc(32, TOTAL_FLOATS * sizeof(float));

    incX = 1;
    incY = 1;

    r_real = 0.0f;
    r_imag = 0.0f;
    ix = 0;
    iy = 0;

    const float scale = 1.0f / RAND_MAX;
    float *x_data = (float *)X;
    float *y_data = (float *)Y;

    for (int j = 0; j < TOTAL_FLOATS; j++) {
        x_data[j] = (float)(rand() * scale);
        y_data[j] = (float)(rand() * scale);
    }
}