#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

void *C;
int ldc;
int i;
int j;
int n1;
int n2;
float beta_real;
float beta_imag;

static float *C_data = NULL;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB of data
    const size_t element_size = 2 * sizeof(float); // Each complex number has real and imag parts

    // Estimate total elements needed
    size_t total_elements = target_bytes / element_size;
    
    // Choose n1 and n2 such that n1 * n2 ≈ total_elements
    n1 = (int)sqrt(total_elements);
    n2 = (int)(total_elements / n1);

    // Adjust ldc to be at least n2, possibly with padding to avoid cache conflicts
    ldc = n2;

    // Allocate C as a 1D array of floats: 2 values per complex number
    C_data = (float *)aligned_alloc(32, 2 * ldc * n1 * sizeof(float));
    if (!C_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize C with non-zero values to make computation meaningful
    for (int idx = 0; idx < 2 * ldc * n1; idx++) {
        C_data[idx] = (float)(rand() % 100) / 100.0f; // Random float in [0,1)
    }

    // Point global C to the allocated buffer
    C = (void *)C_data;

    // Initialize beta to a meaningful complex scaling factor
    beta_real = 0.87f;
    beta_imag = 0.5f;

    // Ensure loop counters are zeroed; they are modified in loop()
    i = 0;
    j = 0;
}