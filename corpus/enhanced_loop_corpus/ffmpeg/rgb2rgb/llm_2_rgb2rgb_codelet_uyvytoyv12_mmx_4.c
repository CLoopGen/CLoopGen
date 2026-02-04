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
    // Variant 1: Consecutive memory access pattern using local pointers with pre-incremented offsets
    uint8_t *local_ydst = ydst;
    uint8_t *local_src = src;
    uint8_t *local_udst = udst;
    uint8_t *local_vdst = vdst;

    for (y = 0; y < height; y += 2) {
        // Access memory in a consecutive manner by directly using pointer arithmetic
        local_ydst = local_ydst + lumStride + lumStride;     // Advance ydst by two rows
        local_src = local_src + srcStride + srcStride;       // Advance src by two rows
        local_udst = local_udst + chromStride;               // One chroma row per two luma rows
        local_vdst = local_vdst + chromStride;               // One chroma row per two luma rows
    }

    // Update the original pointers after loop execution
    ydst = local_ydst;
    src = local_src;
    udst = local_udst;
    vdst = local_vdst;
}
