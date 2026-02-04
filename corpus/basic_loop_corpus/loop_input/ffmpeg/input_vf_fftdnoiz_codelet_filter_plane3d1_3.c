#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *pbuffer;
int block;
int nox;
int noy;
int buffer_linesize;
float sigma;
float limit;
float *cbuffer;
int y;
int x;
int i;
int j;

void init_vars() {
    block = 16;
    nox = 128;
    noy = 128;
    buffer_linesize = 256;
    sigma = 1.0F;
    limit = 0.1F;

    size_t total_size = (size_t)noy * block * buffer_linesize + 64;
    pbuffer = (float*)aligned_alloc(32, total_size * sizeof(float));
    cbuffer = (float*)aligned_alloc(32, total_size * sizeof(float));

    for (size_t i = 0; i < total_size; i++) {
        pbuffer[i] = (float)(drand48() * 2.0 - 1.0);
        cbuffer[i] = (float)(drand48() * 2.0 - 1.0);
    }
}