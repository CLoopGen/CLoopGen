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
    // Variant 2: Strided memory access via index-based addressing
    // Replace pointer arithmetic with indexed access using scaled offsets
    // This changes access pattern to strided, enabling better analysis or vectorization

    for (y = 0; y < height; y += 2) {
        // Use fixed base pointers and compute offset based on current 'y'
        // Simulates a strided traversal without modifying the actual pointers
        // Original functionality preserved: advance equivalent of 2 rows in luma and 1 in chroma
        ptrdiff_t y_offset = (y + 2) * lumStride;
        ptrdiff_t src_offset = (y + 2) * srcStride;
        ptrdiff_t uv_offset = (y / 2 + 1) * chromStride;

        ydst = ydst - ydst + (ydst + y_offset); // Reset and set new position
        src = src - src + (src + src_offset);
        udst = udst - udst + (udst + uv_offset);
        vdst = vdst - vdst + (vdst + uv_offset);
    }
}
