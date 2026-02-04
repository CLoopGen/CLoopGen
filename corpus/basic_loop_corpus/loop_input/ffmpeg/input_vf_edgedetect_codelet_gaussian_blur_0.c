#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w;
int h;
uint8_t *dst;
int dst_linesize;
uint8_t *src;
int src_linesize;
int i;
int j;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    w = 1920;
    h = 1080;
    src_linesize = w + 4;
    dst_linesize = w + 4;

    size_t src_size = (h + 4) * src_linesize;
    size_t dst_size = (h + 4) * dst_linesize;

    src_buffer = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    dst_buffer = (uint8_t*)calloc(dst_size, sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < src_size; idx++) {
        src_buffer[idx] = rand() % 256;
    }

    src = src_buffer + 2 * src_linesize + 2;
    dst = dst_buffer + 2 * dst_linesize + 2;
}

__attribute__((destructor))
static void cleanup() {
    free(src_buffer);
    free(dst_buffer);
}