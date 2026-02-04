#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint16_t *src_r;
uint16_t *src_g;
uint16_t *src_b;
ptrdiff_t linesize_r;
ptrdiff_t linesize_g;
ptrdiff_t linesize_b;
int width;
int height;
int r;
int g;
int b;
int i;
int j;

static uint16_t *buffer_r;
static uint16_t *buffer_g;
static uint16_t *buffer_b;
static size_t total_size;
static size_t row_size;

void init_vars() {
    width = 1024;
    height = 256;
    row_size = width * sizeof(uint16_t);
    total_size = row_size * height;

    buffer_r = (uint16_t*)aligned_alloc(32, total_size);
    buffer_g = (uint16_t*)aligned_alloc(32, total_size);
    buffer_b = (uint16_t*)aligned_alloc(32, total_size);

    if (!buffer_r || !buffer_g || !buffer_b) {
        exit(1);
    }

    memset(buffer_r, 0, total_size);
    memset(buffer_g, 128, total_size);
    memset(buffer_b, 255, total_size);

    src_r = buffer_r;
    src_g = buffer_g;
    src_b = buffer_b;

    linesize_r = row_size / sizeof(uint16_t);
    linesize_g = row_size / sizeof(uint16_t);
    linesize_b = row_size / sizeof(uint16_t);

    r = 0;
    g = 0;
    b = 0;
    i = 0;
    j = 0;
}