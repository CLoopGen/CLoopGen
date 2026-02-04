#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_step;
int len;
uint8_t *a;
int i;

static uint8_t *internal_dst_buffer;
static uint8_t *internal_a_buffer;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 million elements for ~0.01 sec runtime on modern CPU
    dst_step = 1;

    internal_dst_buffer = aligned_alloc(32, (size_t)len * dst_step * sizeof(uint8_t));
    internal_a_buffer = aligned_alloc(32, (size_t)len * sizeof(uint8_t));

    if (!internal_dst_buffer || !internal_a_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    dst = internal_dst_buffer;
    a = internal_a_buffer;

    for (int j = 0; j < len; j++) {
        a[j] = (uint8_t)(j & 0xFF);
    }
}

__attribute__((destructor))
static void cleanup() {
    free(internal_dst_buffer);
    free(internal_a_buffer);
}