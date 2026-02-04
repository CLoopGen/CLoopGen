#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int block = 16;
int nox = 128;
int noy = 128;
int buffer_linesize = 256;
float sigma = 0.1f;
float limit = 0.05f;
float *buffer;

int y;
int x;
int i;
int j;

void init_vars() {
    size_t total_size = (size_t)buffer_linesize * noy * block + (size_t)nox * block * 2;
    float *data = (float *)calloc(total_size, sizeof(float));
    if (!data) {
        fprintf(stderr, "Failed to allocate buffer\n");
        exit(1);
    }
    buffer = data;
}