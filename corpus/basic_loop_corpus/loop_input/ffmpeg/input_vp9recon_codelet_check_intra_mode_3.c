#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

uint8_t *l;
int bytesperpixel;
int n_px_need;
int i;
uint8_t *dst;
ptrdiff_t stride;

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t *l_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    bytesperpixel = 2; // Choose 2 to test both branches, but primarily use the 16-bit path
    n_px_need = DATA_SIZE / 2; // Each pixel takes 2 bytes in l when bytesperpixel=2
    stride = 2;

    // Allocate buffers with padding to prevent out-of-bounds access
    l_buffer = aligned_alloc(32, n_px_need * 2 + 32);
    dst_buffer = aligned_alloc(32, n_px_need * stride + 32);

    if (!l_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize dst: ensure that (&dst[i * stride])[-1] is valid
    // So we need at least one byte before each dst[i * stride]
    // We shift dst pointer by one so that [-1] access is valid
    dst = dst_buffer + 1;
    l = l_buffer;

    // Initialize dst with non-zero data
    for (int i = 0; i < n_px_need * stride; ++i) {
        dst_buffer[i] = (uint8_t)(i & 0xFF);
    }

    // Ensure l is initialized
    for (int i = 0; i < n_px_need * 2; ++i) {
        l_buffer[i] = 0;
    }

    // Set i to zero (loop variable)
    i = 0;
}