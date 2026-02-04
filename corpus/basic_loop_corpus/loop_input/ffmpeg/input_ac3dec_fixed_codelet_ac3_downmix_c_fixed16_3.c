#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t **samples;
int16_t **matrix;
int in_ch = 2;
int len;
int i;
int j;
int v0;
int v1;

void init_vars() {
    len = 131072; // ~256KB of data per channel: 131072 * sizeof(int16_t) * 2 channels ≈ 512KB

    matrix = (int16_t**)calloc(2, sizeof(int16_t*));
    matrix[0] = (int16_t*)calloc(in_ch, sizeof(int16_t));
    matrix[1] = (int16_t*)calloc(in_ch, sizeof(int16_t));

    for (int k = 0; k < in_ch; k++) {
        matrix[0][k] = (int16_t)(k + 1);
        matrix[1][k] = (int16_t)(2 - k);
    }

    samples = (int16_t**)calloc(2, sizeof(int16_t*));
    samples[0] = (int16_t*)calloc(len, sizeof(int16_t));
    samples[1] = (int16_t*)calloc(len, sizeof(int16_t));

    for (int k = 0; k < len; k++) {
        samples[0][k] = (int16_t)((k * 7) & 0x7FFF);
        samples[1][k] = (int16_t)((k * 11) & 0x7FFF);
    }
}