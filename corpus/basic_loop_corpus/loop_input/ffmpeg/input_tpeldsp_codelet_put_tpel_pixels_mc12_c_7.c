#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int stride;
int width;
int height;
int i;
int j;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    width = 4096;
    height = 64;
    stride = width + 1;

    size_t src_size = (height + 1) * (size_t)(stride + 1);
    size_t dst_size = height * (size_t)stride;

    src_buffer = calloc(src_size, sizeof(uint8_t));
    dst_buffer = calloc(dst_size, sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = src_buffer;
    dst = dst_buffer;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}

__attribute__((destructor))
static void destructor() {
    free(src_buffer);
    free(dst_buffer);
}