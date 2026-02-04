#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **in;
int channels = 8;
int len = 1048576; // ~8MB of input data (channels * len * sizeof(int32_t))
int shift = 1;
int16_t *samples;
int i;
int j;

void init_vars() {
    in = malloc(channels * sizeof(int32_t*));
    for (i = 0; i < channels; i++) {
        in[i] = malloc(len * sizeof(int32_t));
        for (j = 0; j < len; j++) {
            in[i][j] = rand() % 65536;
        }
    }

    samples = malloc(channels * len * sizeof(int16_t));
}