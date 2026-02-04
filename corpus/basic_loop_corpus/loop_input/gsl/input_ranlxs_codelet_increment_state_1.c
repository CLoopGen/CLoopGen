#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

double one_bit = 1.0;
int k = 0;
int kmax = 8388608; // Ensures loop runs enough iterations (~8M / 12 ~ 700k iterations)
double _usr_y1 = 0.0;
double y2 = 0.0;
double y3 = 0.0;
double carry = 0.0;

double *xdbl = NULL;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB of data (16,777,216 doubles)
    double *data_region = (double *)aligned_alloc(32, data_size * sizeof(double));
    
    if (!data_region) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    // Initialize all values to avoid NaNs and infinities
    for (size_t i = 0; i < data_size; ++i) {
        data_region[i] = (double)(i % 256) * 0.01;
    }

    xdbl = data_region;

    // Set k and kmax so that k increments by 12 and stays within bounds
    // Each loop iteration accesses indices up to 11, so we need at least 12 elements
    // Ensure kmax is set such that the loop does not cause out-of-bounds access
    // Since no dynamic indexing based on k, only fixed offsets [0..11], any kmax >= 0 with step 12 is safe
    // But we constrain total iterations for timing: ~0.01 sec -> roughly 700k iterations => kmax ~ 8.4M
    k = 0;
}