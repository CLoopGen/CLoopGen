#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float *dst;
int *src0;
int *src1;
int len;
int i;

void init_vars() {
    // Target approximately 0.01 seconds runtime
    // Estimate: ~100 million operations typical for 0.01s on modern CPU
    // Each iteration does two multiplies, one add, and memory ops
    // Use 8e6 elements as reasonable estimate for desired timing
    len = 8000000;

    dst = (float*)aligned_alloc(32, len * sizeof(float));
    src0 = (int*)aligned_alloc(32, len * sizeof(int));
    src1 = (int*)aligned_alloc(32, len * sizeof(int));

    // Initialize arrays with pseudo-random data
    srand(12345);
    for (int j = 0; j < len; j++) {
        src0[j] = rand() - RAND_MAX/2;
        src1[j] = rand() - RAND_MAX/2;
        dst[j] = 0.0f;
    }

    i = 0;
}