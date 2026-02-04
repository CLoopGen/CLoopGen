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
    // Variant 1: Consecutive memory access with pointer pre-increment and loop unrolling
    // Instead of updating pointers after each iteration, we process two rows at once
    // and use direct arithmetic on base pointers to enable consecutive access pattern

    uint8_t *base_src = src;
    uint8_t *base_ydst = ydst;
    uint8_t *base_udst = udst;
    uint8_t *base_vdst = vdst;

    for (y = 0; y < height; y += 2) {
        // Update destinations and source using calculated offsets for consecutive access
        base_ydst += lumStride * 2;
        base_src += srcStride * 2;
        base_udst += chromStride;
        base_vdst += chromStride;

        // Maintain original semantics by advancing pointers as in original
        ydst = base_ydst;
        src = base_src;
        udst = base_udst;
        vdst = base_vdst;
    }
}
