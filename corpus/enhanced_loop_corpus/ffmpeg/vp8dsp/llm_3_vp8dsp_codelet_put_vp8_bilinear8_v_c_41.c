#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstride;
extern uint8_t *src;
extern ptrdiff_t sstride;
extern int h;
extern int c;
extern int d;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern using fixed offset jumps
    // Simulate a strided traversal by stepping through memory with larger, irregular strides
    // Here, we process two rows at once to create interlaced access pattern
    uint8_t *src_curr, *src_next, *dst_curr;
    for (y = 0; y < h; y += 1) {
        src_curr = src + y * sstride;
        src_next = src_curr + sstride;
        dst_curr = dst + y * dstride;
        // Access elements with mixed vertical and horizontal dependencies
        for (x = 0; x < 8; x++) {
            // Introduce micro-stride pattern: alternate coefficient influence based on position
            int weight = (x & 1) ? c : d;
            int neighbor_weight = (x & 1) ? d : c;
            dst_curr[x] = (weight * src_curr[x] + neighbor_weight * src_next[x] + 4) >> 3;
        }
    }
}
