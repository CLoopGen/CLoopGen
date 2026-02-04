#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len = 1 << 20;
int shift = 2;
int i;

int32_t **in;
int16_t *samples;

void init_vars() {
    in = malloc(2 * sizeof(int32_t*));
    if (!in) exit(1);

    in[0] = malloc(len * sizeof(int32_t));
    in[1] = malloc(len * sizeof(int32_t));
    samples = malloc(2 * len * sizeof(int16_t));

    if (!in[0] || !in[1] || !samples) exit(1);

    for (int j = 0; j < len; j++) {
        in[0][j] = rand() % 1000;
        in[1][j] = rand() % 1000;
    }
}