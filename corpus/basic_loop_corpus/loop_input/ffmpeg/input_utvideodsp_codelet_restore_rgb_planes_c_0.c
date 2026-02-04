#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src_r;
uint8_t *src_g;
uint8_t *src_b;
ptrdiff_t linesize_r;
ptrdiff_t linesize_g;
ptrdiff_t linesize_b;
int width;
int height;
uint8_t r;
uint8_t g;
uint8_t b;
int i;
int j;

static uint8_t *buffer_r;
static uint8_t *buffer_g;
static uint8_t *buffer_b;

void init_vars() {
    width = 1920;
    height = 1080;
    linesize_r = width;
    linesize_g = width;
    linesize_b = width;

    size_t total_size = (size_t)width * height;

    buffer_r = (uint8_t*)aligned_alloc(32, total_size);
    buffer_g = (uint8_t*)aligned_alloc(32, total_size);
    buffer_b = (uint8_t*)aligned_alloc(32, total_size);

    if (!buffer_r || !buffer_g || !buffer_b) {
        exit(1);
    }

    src_r = buffer_r;
    src_g = buffer_g;
    src_b = buffer_b;

    for (size_t idx = 0; idx < total_size; idx++) {
        buffer_r[idx] = rand() % 256;
        buffer_g[idx] = rand() % 256;
        buffer_b[idx] = rand() % 256;
    }

    r = 0;
    g = 0;
    b = 0;
    i = 0;
    j = 0;
}