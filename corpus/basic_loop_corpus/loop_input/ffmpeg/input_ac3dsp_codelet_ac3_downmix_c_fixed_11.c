#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **samples;
int16_t **matrix;
int in_ch = 2;
int len;
int i;
int j;
int64_t v0;
int64_t v1;

void init_vars() {
    len = 65536; // Adjusted for ~0.01 sec runtime

    matrix = (int16_t **)calloc(2, sizeof(int16_t *));
    matrix[0] = (int16_t *)calloc(in_ch, sizeof(int16_t));
    matrix[1] = (int16_t *)calloc(in_ch, sizeof(int16_t));

    for (int c = 0; c < in_ch; c++) {
        matrix[0][c] = (int16_t)(c + 1);
        matrix[1][c] = (int16_t)(2 - c);
    }

    samples = (int32_t **)calloc(2, sizeof(int32_t *));
    for (int c = 0; c < 2; c++) {
        samples[c] = (int32_t *)calloc(len, sizeof(int32_t));
        for (int idx = 0; idx < len; idx++) {
            samples[c][idx] = (int32_t)(idx % 65536);
        }
    }
}