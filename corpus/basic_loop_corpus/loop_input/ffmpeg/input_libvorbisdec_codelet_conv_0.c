#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int samples = 65536;
float **pcm;
int channels = 8;
int i;
int j;
float *mono;

void init_vars() {
    pcm = (float**)calloc(channels, sizeof(float*));
    for (int c = 0; c < channels; c++) {
        pcm[c] = (float*)calloc(samples, sizeof(float));
    }
}