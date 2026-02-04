#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *d;
uint8_t *top;
uint8_t *left;
ptrdiff_t stride;
int x;
int y;

static uint8_t *d_buffer;
static uint8_t *top_buffer;
static uint8_t *left_buffer;

void init_vars() {
    // Allocate d as a 16x16 block to allow for 8x8 writes with stride handling
    const size_t d_size = 256 * 1024 * 1024; // ~256MB total data to hit ~0.01s runtime
    d_buffer = calloc(d_size, 1);
    if (!d_buffer) exit(1);
    
    // We'll use an effective 8x8 block written into d with a stride of 16
    stride = 16;
    d = d_buffer;

    // top and left arrays need to support indices from (x+y+2)-1 to (x+y+2)+1
    // Max index accessed: x=7, y=7 => offset = 7+7+2 = 16, so we need up to index 17
    // Min index: x=0,y=0 => offset-1 = 0+0+2-1 = 1, but we access -1 relative to base
    // So we need array from index 0 to at least 18 to cover [pos-1, pos+1]
    top_buffer = calloc(32, 1);
    if (!top_buffer) exit(1);
    top = top_buffer + 1; // shift so that we can access [-1] safely

    left_buffer = calloc(32, 1);
    if (!left_buffer) exit(1);
    left = left_buffer + 1; // same offset for left

    // Initialize top and left with non-zero values to make computation meaningful
    for (int i = -1; i <= 18; i++) {
        top[i] = (i * i + 17) & 0xFF;
        left[i] = (i * i + 23) & 0xFF;
    }

    // Initialize d to zero (already done by calloc)
    x = 0;
    y = 0;
}