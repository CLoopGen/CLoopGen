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
int i;
int ix;
int iy;
float alpha_real;
float alpha_imag;

static float X_data[65536] __attribute__((aligned(32)));
static float Y_data[65536] __attribute__((aligned(32)));

void init_vars() {
    const size_t element_size = sizeof(float);
    const size_t total_elements = 65536;
    const size_t complex_elements = total_elements / 2;
    
    N = 16384;
    alpha_real = 1.5f;
    alpha_imag = 0.8f;
    incX = 1;
    incY = 1;
    ix = 0;
    iy = 0;

    X = X_data;
    Y = Y_data;

    for (size_t j = 0; j < total_elements; j++) {
        X_data[j] = (rand() % 1000) / 100.0f;
    }

    for (size_t j = 0; j < total_elements; j++) {
        Y_data[j] = (rand() % 1000) / 100.0f;
    }
}