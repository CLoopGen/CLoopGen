#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 1 << 20;
int shift = 2;
int i;

int32_t **in;
int32_t **samples;

void init_vars() {
    in = (int32_t **)calloc(2, sizeof(int32_t *));
    samples = (int32_t **)calloc(2, sizeof(int32_t *));

    in[0] = (int32_t *)calloc(len, sizeof(int32_t));
    in[1] = (int32_t *)calloc(len, sizeof(int32_t));
    samples[0] = (int32_t *)calloc(len, sizeof(int32_t));
    samples[1] = (int32_t *)calloc(len, sizeof(int32_t));

    for (int j = 0; j < len; j++) {
        in[0][j] = rand() % 1000;
        in[1][j] = rand() % 1000;
    }
}