#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int stride;
int block_size;
int y;
int sum;

static uint8_t *internal_src_buffer;
static int allocated_size;

void init_vars() {
    block_size = 4096;
    stride = block_size;
    allocated_size = stride * block_size;
    internal_src_buffer = (uint8_t*)calloc(allocated_size, sizeof(uint8_t));
    if (!internal_src_buffer) {
        exit(1);
    }
    src = internal_src_buffer;
    sum = 0;
    y = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(internal_src_buffer);
    internal_src_buffer = NULL;
}