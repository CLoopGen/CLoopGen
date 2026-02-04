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
    width = 2048;
    height = 1024;
    stride = width + 1;

    size_t src_size = (height + 1) * (size_t)(stride + 1);
    size_t dst_size = height * (size_t)stride;

    src_buffer = calloc(src_size, sizeof(uint8_t));
    dst_buffer = calloc(dst_size, sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = rand() & 0xFF;
    }

    src = src_buffer;
    dst = dst_buffer;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}

__attribute__((destructor))
static void destructor_free() {
    free(src_buffer);
    free(dst_buffer);
}