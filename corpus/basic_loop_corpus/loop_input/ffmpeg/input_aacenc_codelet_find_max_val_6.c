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
    maxval = 0.0f;
    scaled = (float*)malloc(group_len * 128 * sizeof(float));
    srand((unsigned int)time(NULL));
    for (int idx = 0; idx < group_len * 128; idx++) {
        scaled[idx] = (float)(rand()) / RAND_MAX * 100.0f;
    }
}