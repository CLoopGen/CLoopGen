#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int group_len = 2048;
int swb_size = 128;
float *scaled;
float maxval = 0.0f;
int w2;
int i;

void init_vars() {
    scaled = (float *)aligned_alloc(32, sizeof(float) * (size_t)(group_len * 128));
    if (!scaled) {
        exit(1);
    }
    for (int idx = 0; idx < group_len * 128; idx++) {
        scaled[idx] = (float)(rand()) / RAND_MAX * 100.0f;
    }
    maxval = 0.0f;
}