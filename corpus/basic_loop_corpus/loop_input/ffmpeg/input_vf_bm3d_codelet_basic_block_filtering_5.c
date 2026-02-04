#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

int nb_match_blocks = 1024;
int block_size = 64;
int pgroup_size = 1024;

float *bufferz = NULL;
float threshold[4] = {0.1f, 0.2f, 0.3f, 0.4f};
int retained = 0;
int i = 0;
int j = 0;
int k = 0;

void init_vars() {
    const size_t total_elements = (size_t)block_size * block_size * pgroup_size;
    bufferz = (float*)aligned_alloc(32, total_elements * sizeof(float));
    if (!bufferz) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_elements; idx++) {
        bufferz[idx] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
    }

    retained = 0;
}