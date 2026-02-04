#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern uint8_t *qp_store;
extern int qp_stride;
extern int x;
extern int y;
extern int qpsum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed loop order and stride-based traversal (access every 2nd block, then backfill)
    // Simulates irregular but deterministic access pattern for potential prefetching effects
    int step = 2;
    // First pass: even-indexed blocks
    for (y = 0; y < (height >> 4); y += step) {
        for (x = 0; x < (width >> 4); x += step) {
            qpsum += qp_store[x + y * qp_stride];
        }
    }
    // Second pass: odd-indexed blocks to maintain correctness
    for (y = 1; y < (height >> 4); y += step) {
        for (x = 1; x < (width >> 4); x += step) {
            qpsum += qp_store[x + y * qp_stride];
        }
    }
    // Handle edge fills if width>>4 or height>>4 is odd (optional fine-tuning)
    for (y = 0; y < (height >> 4); y++) {
        for (x = (x % step == 0) ? 1 : 0; x < (width >> 4); x += step*step) {
            if ((x & 1) != ((y & 1))) continue;
            qpsum += qp_store[x + y * qp_stride];
        }
    }
}
