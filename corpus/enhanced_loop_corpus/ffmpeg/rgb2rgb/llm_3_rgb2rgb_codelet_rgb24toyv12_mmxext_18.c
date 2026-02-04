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
for (y = 0; y < height - 2; y += 2) {
    // Change to strided memory access by unrolling and accessing non-consecutive rows directly
    uint8_t *src_row0 = src;
    uint8_t *src_row1 = src + srcStride;
    uint8_t *src_row2 = src + srcStride * 2;
    uint8_t *src_row3 = src + srcStride * 3;

    uint8_t *ydst_row1 = ydst + lumStride;
    uint8_t *ydst_row2 = ydst + lumStride * 2;

    // Use strided accesses: jump over intermediate rows, simulate processing
    *ydst_row1 = *src_row1;
    *ydst_row2 = *src_row2;

    // Update pointers for next iteration
    ydst += lumStride * 2;
    src += srcStride * 2;
    udst += chromStride;
    vdst += chromStride;
}
}
