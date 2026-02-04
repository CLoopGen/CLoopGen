#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

int group_len;
int swb_size;
float *scaled;
float maxval;
int w2;
int i;

void init_vars() {
    group_len = 1024;
    swb_size = 128;

    size_t total_size = (size_t)group_len * swb_size;
    scaled = (float *)malloc(total_size * sizeof(float));

    if (!scaled) {
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < total_size; ++idx) {
        scaled[idx] = ((float)rand() / (float)RAND_MAX) * 100.0f;
    }

    maxval = -1.0f;
}