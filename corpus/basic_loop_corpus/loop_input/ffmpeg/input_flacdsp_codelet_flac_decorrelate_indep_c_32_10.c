#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t **in;
int channels = 8;
int len = 4096;
int shift = 2;
int32_t *samples;
int i;
int j;

void init_vars() {
    // Allocate and initialize 'in' as a 2D array of int32_t with dimensions [channels][len]
    in = (int32_t**)calloc(channels, sizeof(int32_t*));
    for (i = 0; i < channels; i++) {
        in[i] = (int32_t*)calloc(len, sizeof(int32_t));
        for (j = 0; j < len; j++) {
            in[i][j] = rand() % 1000; // arbitrary initialization
        }
    }

    // Allocate samples to hold channels * len elements
    samples = (int32_t*)malloc(channels * len * sizeof(int32_t));
}