#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
uint32_t row;

static uint8_t *internal_src_buffer;
static uint8_t *internal_dst_buffer;
static size_t total_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

void init_vars() {
    if (internal_src_buffer == NULL) {
        internal_src_buffer = aligned_alloc(32, total_size);
        internal_dst_buffer = aligned_alloc(32, total_size);
    }

    if (!internal_src_buffer || !internal_dst_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    src = internal_src_buffer;
    dst = internal_dst_buffer;
    stride = 64; // typical cache line multiple, fits within estimated data size
}

__attribute__((destructor))
static void cleanup() {
    free(internal_src_buffer);
    free(internal_dst_buffer);
}