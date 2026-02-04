#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **samples;
int16_t **matrix;
int in_ch = 8;
int len = 32768;
int i;
int j;
int64_t v0;

void init_vars() {
    // Allocate samples: in_ch x len
    samples = (int32_t**)calloc(in_ch, sizeof(int32_t*));
    for (int idx = 0; idx < in_ch; idx++) {
        samples[idx] = (int32_t*)calloc(len, sizeof(int32_t));
        for (int jdx = 0; jdx < len; jdx++) {
            samples[idx][jdx] = rand() % 1024;
        }
    }

    // Allocate matrix: 1 x in_ch
    matrix = (int16_t**)calloc(1, sizeof(int16_t*));
    matrix[0] = (int16_t*)calloc(in_ch, sizeof(int16_t));
    for (int idx = 0; idx < in_ch; idx++) {
        matrix[0][idx] = (int16_t)(rand() % 512 - 256);
    }
}