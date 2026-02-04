#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t src_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided write with indirect addressing via index array
    // Instead of direct indexing, use an index array to simulate irregular but deterministic write pattern
    // This models scenarios like gather/scatter operations or non-contiguous buffer mapping
    int *indices = (int*)alloca(w * sizeof(int));
    for (x = 0; x < w; x++) {
        indices[x] = x * 2; // Example: writing to even indices only (strided write)
    }
    for (y = 0; y < h; y++) {
        uint8_t *dst_row = dst + y * dst_linesize;
        for (x = 0; x < w; x++) {
            dst_row[indices[x]] = src[x * src_linesize]; // Strided write using indirect addressing
        }
    }
}
