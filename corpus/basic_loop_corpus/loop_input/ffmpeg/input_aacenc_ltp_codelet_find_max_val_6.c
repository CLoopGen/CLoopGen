#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int group_len = 2048;
int swb_size = 128;
float *scaled;
float maxval = 0.0f;
int w2;
int i;

void init_vars() {
    size_t total_size = group_len * 128;
    scaled = (float*)aligned_alloc(32, total_size * sizeof(float));
    
    if (!scaled) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        scaled[idx] = (float)(rand() % 10000) / 100.0f;
    }

    maxval = 0.0f;
}