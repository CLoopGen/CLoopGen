#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *block;
int width = 1024;
int height = 1024;
int stride = 1024;
float threshold = 0.5f;
float frac = 0.8f;
float shift = 0.2f;
int y;
int x;

void init_vars() {
    size_t total_size = (size_t)height * (size_t)stride;
    float *data = (float *)calloc(total_size, sizeof(float));
    if (!data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (size_t i = 0; i < total_size; i++) {
        data[i] = (float)(i % 256 - 128) / 64.0f;
    }
    block = data;
}