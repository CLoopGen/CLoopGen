#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

uint8_t *dst;
ptrdiff_t dststride;
uint8_t *src;
ptrdiff_t srcstride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;

#define FILTER_SIZE 6
#define CM_SIZE 256
#define HEIGHT_FACTOR 1024
#define WIDTH 4
#define SRC_PADDING 3  // maximum backward/forward access: -2 and +3

static uint8_t internal_filter[FILTER_SIZE] = {8, 12, 16, 20, 24, 28};
static uint8_t internal_cm[CM_SIZE];
static uint8_t *internal_src_buffer;
static uint8_t *internal_dst_buffer;

void init_vars() {
    // Initialize filter and cm
    filter = internal_filter;
    cm = internal_cm;
    
    // Fill cm with identity mapping (clamp to 0-255)
    for (int i = 0; i < CM_SIZE; i++) {
        cm[i] = (uint8_t)(i & 0xFF);
    }

    // Set dimensions
    h = HEIGHT_FACTOR;

    // Each row accesses src[x + offset] for x in [0,3] and offsets from -2 to +3
    // So we need at least 3 extra before and after the valid data
    int row_width = WIDTH + 2 * SRC_PADDING;
    srcstride = row_width;
    dststride = WIDTH;

    // Allocate buffers with padding
    internal_src_buffer = aligned_alloc(32, (size_t)h * (size_t)srcstride * sizeof(uint8_t));
    internal_dst_buffer = aligned_alloc(32, (size_t)h * (size_t)dststride * sizeof(uint8_t));

    if (!internal_src_buffer || !internal_dst_buffer) {
        internal_src_buffer = NULL;
        internal_dst_buffer = NULL;
        exit(1);
    }

    // Initialize source buffer with non-zero values
    for (int i = 0; i < h * srcstride; i++) {
        internal_src_buffer[i] = (uint8_t)((i * 17 + 13) & 0xFF);
    }

    // Set global pointers
    src = internal_src_buffer + SRC_PADDING;  // Shift so that base points after left padding
    dst = internal_dst_buffer;

    // Ensure no memory is left uninitialized
    memset(internal_dst_buffer, 0, (size_t)h * (size_t)dststride * sizeof(uint8_t));
}