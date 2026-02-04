#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
ptrdiff_t dststride;
uint8_t *src;
ptrdiff_t srcstride;
int h;
uint8_t *filter;
uint8_t *cm;
int x;
int y;

#define DATA_SIZE (128 << 20) // 128 MB total data size target

static uint8_t *dst_buffer;
static uint8_t *src_buffer;
static uint8_t filter_buffer[5];
static uint8_t cm_buffer[256];

void init_vars() {
    // Initialize constants used in loop
    h = 8192; // Adjust to control height
    dststride = 16;
    srcstride = 16;

    // Allocate buffers with proper alignment and padding
    dst_buffer = aligned_alloc(32, DATA_SIZE);
    src_buffer = aligned_alloc(32, DATA_SIZE);

    if (!dst_buffer || !src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize source data
    for (size_t i = 0; i < DATA_SIZE; i++) {
        src_buffer[i] = rand() & 0xFF;
    }

    // Initialize cm table: identity mapping with clipping
    for (int i = 0; i < 256; i++) {
        cm_buffer[i] = i;
    }

    // Initialize filter coefficients
    filter_buffer[0] = 0;      // unused
    filter_buffer[1] = 16;     // negative weight
    filter_buffer[2] = 48;     // center weight
    filter_buffer[3] = 16;     // positive neighbor
    filter_buffer[4] = 8;      // far neighbor

    // Set external pointers
    dst = dst_buffer;
    src = src_buffer;
    filter = filter_buffer;
    cm = cm_buffer;

    // Ensure no out-of-bounds access in loop:
    // In inner loop: accesses src[x-1], src[x], src[x+1], src[x+2]
    // So we need at least x+2 < width => width >= 10 (x goes to 7)
    // Each row accessed with stride srcstride = 16, so each row has 16 bytes usable
    // We have h rows, so total src size should be at least h * srcstride
    // Our allocation is much larger than needed, but safe
}