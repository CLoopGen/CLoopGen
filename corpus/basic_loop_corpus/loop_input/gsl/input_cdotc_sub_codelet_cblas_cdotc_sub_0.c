#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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

static float *X_data;
static float *Y_data;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of float data (~256M bytes)
    const int num_elements = data_size / sizeof(float) / 2; // Each complex number has 2 floats

    N = num_elements;
    incX = 1;
    incY = 1;
    r_real = 0.0f;
    r_imag = 0.0f;
    ix = 0;
    iy = 0;

    X_data = aligned_alloc(32, data_size);
    Y_data = aligned_alloc(32, data_size);

    if (!X_data || !Y_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < num_elements * 2; j++) {
        X_data[j] = (float)(j % 128) / 64.0f;
        Y_data[j] = (float)((j + 32) % 128) / 64.0f;
    }

    X = (void*)X_data;
    Y = (void*)Y_data;
}