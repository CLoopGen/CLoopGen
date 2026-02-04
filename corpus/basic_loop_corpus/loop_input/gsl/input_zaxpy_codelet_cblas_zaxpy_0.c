#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

int N;
void *X;
int incX;
void *Y;
int incY;
int i;
int ix;
int iy;
double alpha_real;
double alpha_imag;

static double X_data[1 << 24]; // ~16M doubles = 128 MB
static double Y_data[1 << 24]; // ~16M doubles = 128 MB

void init_vars() {
    const size_t max_elements = 1 << 23; // Max safe elements to avoid overflow in indexing
    const double cpu_freq_ghz = 3.0;
    const double target_time_seconds = 0.01;
    const double operations_per_iteration = 10;
    const double estimated_iterations = target_time_seconds * cpu_freq_ghz * 1e9 / operations_per_iteration;

    N = (int)(estimated_iterations);
    if (N > max_elements / 2) N = max_elements / 2;
    if (N < 1) N = 1;

    X = X_data;
    Y = Y_data;

    incX = 1;
    incY = 1;

    ix = 0;
    iy = 0;

    alpha_real = 1.5;
    alpha_imag = -0.8;

    memset(X_data, 0, N * 2 * sizeof(double));
    memset(Y_data, 0, N * 2 * sizeof(double));

    for (int idx = 0; idx < N * 2; idx++) {
        X_data[idx] = (double)(idx % 127) / 10.0;
        Y_data[idx] = (double)((idx + 10) % 113) / 11.0;
    }
}