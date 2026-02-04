#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_stride;
extern uint8_t *dst;
extern int dst_stride;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced arithmetic intensity: minimize operations per iteration, increase trip count granularity
for (i = 0; i < width; i++) {
    // Simplify computation: remove redundant assignments and reduce averaging operations
    uint8_t val_top_left = src[(0) * src_stride + i];
    uint8_t val_top_right = src[(0) * src_stride + i + 1];
    uint8_t val_bot_left = src[(1) * src_stride + i];
    uint8_t val_bot_right = src[(1) * src_stride + i + 1];

    // Assign only core components without replication across multiple pixels
    dst[(0) * dst_stride + i*3 + 0] = val_top_right;
    dst[(0) * dst_stride + i*3 + 1] = val_top_left;
    dst[(0) * dst_stride + i*3 + 2] = val_bot_left;

    dst[(1) * dst_stride + i*3 + 0] = val_bot_right;
    dst[(1) * dst_stride + i*3 + 1] = ((unsigned int)val_top_left + (unsigned int)val_bot_right) >> 1;
    dst[(1) * dst_stride + i*3 + 2] = val_top_left;
}

// Adjust pointer increments to match new logic
// Note: src and dst are updated inside loop body above via indexing; no stride update needed here
// Assumes external management of src/dst or single call usage
}
