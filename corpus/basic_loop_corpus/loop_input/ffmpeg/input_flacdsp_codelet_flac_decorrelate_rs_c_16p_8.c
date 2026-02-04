#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 1 << 20;
int shift = 2;
int i;

int32_t **in;
int16_t **samples;

void init_vars() {
    in = (int32_t**)calloc(2, sizeof(int32_t*));
    samples = (int16_t**)calloc(2, sizeof(int16_t*));

    for (int idx = 0; idx < 2; idx++) {
        in[idx] = (int32_t*)calloc(len, sizeof(int32_t));
        samples[idx] = (int16_t*)calloc(len, sizeof(int16_t));
    }

    for (int j = 0; j < len; j++) {
        in[0][j] = rand() & 0xFFFFF;
        in[1][j] = rand() & 0xFFFFF;
    }
}