#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *fc_out;
int16_t *fc_in;
int16_t *filter;
int len;
int i;
int k;

void init_vars() {
    len = 8192;

    fc_in = (int16_t*)aligned_alloc(32, len * sizeof(int16_t));
    fc_out = (int16_t*)aligned_alloc(32, len * sizeof(int16_t));
    filter = (int16_t*)aligned_alloc(32, len * sizeof(int16_t));

    for (int idx = 0; idx < len; idx++) {
        fc_in[idx] = (rand() % 256) - 128;
        fc_out[idx] = 0;
        filter[idx] = (rand() % 256) - 128;
    }
}