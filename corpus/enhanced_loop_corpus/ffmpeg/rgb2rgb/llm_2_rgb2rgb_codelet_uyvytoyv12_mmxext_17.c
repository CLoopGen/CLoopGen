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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 iterations
    // Instead of updating pointers after each logical iteration, we pre-calculate the total offset
    // and access memory in a more sequential pattern for better cache locality.
    uint8_t *src_temp = src;
    uint8_t *ydst_temp = ydst;
    uint8_t *udst_temp = udst;
    uint8_t *vdst_temp = vdst;

    for (int i = 0; i < height; i += 2) {
        // Simulate two steps: process current and next row together
        ydst_temp += lumStride * 2;
        src_temp += srcStride * 2;
        udst_temp += chromStride;
        vdst_temp += chromStride;
    }

    // Update global pointers only once at the end to reflect final position
    ydst = ydst_temp;
    src = src_temp;
    udst = udst_temp;
    vdst = vdst_temp;
}
