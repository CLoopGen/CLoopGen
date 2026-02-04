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
    // Variant 2: Strided memory access using index-based addressing instead of pointer arithmetic
    // Access arrays through calculated byte offsets to simulate strided access patterns,
    // which may be useful for SIMD or when aligning with specific memory banks.
    int total_y_steps = height / 2;

    for (int i = 0; i < total_y_steps; i++) {
        int src_offset = (i * 2 + 2) * srcStride;  // Advance 2 rows each time
        int ydst_offset = (i * 2 + 2) * lumStride;
        int uvdst_offset = (i + 1) * chromStride;

        // Use base addresses with explicit indexing (strided access)
        src = &src[src_offset];
        ydst = &ydst[ydst_offset];
        udst = &udst[uvdst_offset];
        vdst = &vdst[uvdst_offset];
    }
}
