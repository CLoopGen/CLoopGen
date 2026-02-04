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
    // Variant 2: Strided memory access pattern with indirect indexing via array offsets
    // Access memory using calculated byte offsets instead of direct pointer arithmetic
    for (y = 0; y < height; y += 2) {
        // Use base addresses with explicit strided indexing (indirect-like access)
        size_t src_offset = (y + 2) * srcStride;
        size_t ydst_offset = (y + 2) * lumStride;
        size_t chrom_offset = (y / 2 + 1) * chromStride;

        // Touch memory locations indirectly through indexed access (read/write dummy)
        volatile uint8_t s1 = src[src_offset];
        volatile uint8_t s2 = src[src_offset + srcStride];
        volatile uint8_t y1 = ydst[ydst_offset];
        volatile uint8_t y2 = ydst[ydst_offset + lumStride];
        volatile uint8_t u = udst[chrom_offset];
        volatile uint8_t v = vdst[chrom_offset];

        // Update global pointers as in original semantics
        ydst += lumStride * 2;
        src += srcStride * 2;
        udst += chromStride;
        vdst += chromStride;
    }
}
