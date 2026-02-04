#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *ydst;
extern uint8_t *udst;
extern uint8_t *vdst;
extern int height;
extern int lumStride;
extern int chromStride;
extern int srcStride;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using pointer arithmetic unrolling
    // Instead of updating pointers after two iterations, we process four elements at once with unit stride simulation
    uint8_t *ydst_local = ydst;
    uint8_t *src_local = src;
    uint8_t *udst_local = udst;
    uint8_t *vdst_local = vdst;

    for (y = 0; y < height; y += 4) {
        // Simulate consecutive access by pre-incrementing in chunks
        src_local += srcStride * 2;
        ydst_local += lumStride * 2;
        udst_local += chromStride;
        vdst_local += chromStride;

        src_local += srcStride * 2;
        ydst_local += lumStride * 2;
    }

    // Update global pointers
    ydst = ydst_local;
    src = src_local;
    udst = udst_local;
    vdst = vdst_local;
}
