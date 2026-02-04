#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int group_len;
int swb_size;
float *scaled;
float maxval;
int w2;
int i;

void init_vars() {
    group_len = 1024;
    swb_size = 128;
    scaled = (float *)aligned_alloc(32, group_len * 128 * sizeof(float));
    if (!scaled) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    for (int idx = 0; idx < group_len * 128; idx++) {
        scaled[idx] = (float)(rand()) / RAND_MAX * 100.0f;
    }
    maxval = 0.0f;
}

__attribute__((destructor))
static void cleanup() {
    if (scaled) {
        free(scaled);
    }
}