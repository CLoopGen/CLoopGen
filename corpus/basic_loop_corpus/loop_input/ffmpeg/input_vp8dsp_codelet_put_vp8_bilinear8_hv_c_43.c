#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dstride;
int h;
int c;
int d;
int x;
int y;
uint8_t *tmp;

#define DATA_SIZE (128 * 1024 * 1024) // ~128MB of data for sufficient runtime

static uint8_t *dst_buffer;
static uint8_t *tmp_buffer;

void init_vars() {
    h = 16384;  // Adjust to ensure total processed data reaches target size
    dstride = 16;
    c = 5;
    d = 3;

    // Allocate buffers with proper sizes to prevent out-of-bounds access
    dst_buffer = aligned_alloc(32, h * dstride);
    tmp_buffer = aligned_alloc(32, h * 16); // Each iteration reads up to x+8, so need 16 per row

    // Initialize pointers
    dst = dst_buffer;
    tmp = tmp_buffer;

    // Initialize tmp data to avoid undefined behavior
    for (int i = 0; i < h * 16; i++) {
        tmp_buffer[i] = rand() & 0xFF;
    }
}