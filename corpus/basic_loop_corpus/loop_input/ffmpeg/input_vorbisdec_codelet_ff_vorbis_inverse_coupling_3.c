#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float *mag;
float *ang;
intptr_t blocksize;
int i;

void init_vars() {
    blocksize = 64 * 1024 * 1024 / sizeof(float);  // ~256 MB total data (two arrays)

    mag = (float*)aligned_alloc(32, blocksize * sizeof(float));
    ang = (float*)aligned_alloc(32, blocksize * sizeof(float));

    if (!mag || !ang) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (i = 0; i < blocksize; i++) {
        mag[i] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;  // [-1.0, 1.0]
        ang[i] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;  // [-1.0, 1.0]
    }
}