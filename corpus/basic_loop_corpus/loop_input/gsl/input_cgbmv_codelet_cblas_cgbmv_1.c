#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

#define DATA_SIZE (128 << 20) // 128 MB of data

static float *Y_data;
void *Y;
int incY;
int i;
int lenY;
float beta_real;
float beta_imag;
int iy;

void init_vars() {
    // Initialize scalar values
    beta_real = 1.5f;
    beta_imag = 0.8f;
    incY = 1;  // typical stride

    // Allocate Y as array of complex<float> (2 floats per element)
    Y_data = aligned_alloc(32, DATA_SIZE);
    if (!Y_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize Y to point to the data (array of float pairs)
    Y = Y_data;

    // Set total number of iterations based on available data
    lenY = (DATA_SIZE / sizeof(float)) / 2;  // number of complex elements

    // Initialize starting index
    iy = 0;

    // Ensure we don't exceed bounds: each iteration accesses 2*(iy) and 2*(iy)+1
    // With incY >= 1 and lenY set as above, the maximum accessed index is:
    // 2*(iy + (lenY-1)*incY) + 1 <= 2*(lenY-1)*incY + 2*0 + 1
    // We assume worst-case incY=1 -> max index ~ 2*lenY, which fits by construction.

    // Seed and initialize Y with random data to avoid optimization removal
    srand((unsigned int)time(NULL));
    for (int j = 0; j < (int)(DATA_SIZE / sizeof(float)); j++) {
        Y_data[j] = ((float)rand()) / RAND_MAX;
    }
}