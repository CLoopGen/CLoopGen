#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_step;
uint8_t *src;
int src_step;
int len;
int radius;
int inv;
int x;
int sum;

void init_vars() {
    len = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
    radius = 100;
    inv = 12345;
    x = radius + 1; // Ensure (x - radius - 1) >= 0 at start
    sum = 0;
    dst_step = 1;
    src_step = 1;

    // Allocate src with padding to ensure (2*len - radius - x - 1) is valid when x starts at radius+1
    // Max index into src: (2*len - radius - x - 1) when x = radius+1 => 2*len - 2*radius - 2
    // Also need to access (x - radius - 1) which at x=radius+1 is 0
    size_t src_size = (2 * len) + 100;
    src = (uint8_t*)aligned_alloc(32, src_size * sizeof(uint8_t));
    if (!src) exit(1);

    // Allocate dst: at least len elements
    dst = (uint8_t*)aligned_alloc(32, len * dst_step * sizeof(uint8_t));
    if (!dst) exit(1);

    // Initialize src with non-zero data
    for (size_t i = 0; i < src_size; i++) {
        src[i] = (uint8_t)(i & 0xFF);
    }

    // Ensure no out-of-bounds: loop runs x from current value to len-1
    // Final condition: x < len
    // We set x initially to radius+1, so we require radius+1 < len
    if (len <= radius + 1) {
        len = radius + 2;
        dst = (uint8_t*)realloc(dst, len * dst_step * sizeof(uint8_t));
        if (!dst) exit(1);
    }
}