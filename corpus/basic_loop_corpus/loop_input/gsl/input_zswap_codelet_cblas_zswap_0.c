#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
void *X;
int incX;
void *Y;
int incY;
int i;
int ix;
int iy;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to ensure ~0.01s runtime
    const size_t num_complex_elements = data_size / (2 * sizeof(double));
    
    N = (int)num_complex_elements;

    X = aligned_alloc(32, data_size);
    Y = aligned_alloc(32, data_size);

    incX = 1;
    incY = 1;

    ix = 0;
    iy = 0;

    // Initialize X and Y with dummy data
    double (*x_complex)[2] = (double(*)[2])X;
    double (*y_complex)[2] = (double(*)[2])Y;

    for (int idx = 0; idx < N; idx++) {
        x_complex[idx][0] = 1.0 + idx;
        x_complex[idx][1] = -1.0 - idx;
        y_complex[idx][0] = 10.0 + idx;
        y_complex[idx][1] = -10.0 - idx;
    }
}