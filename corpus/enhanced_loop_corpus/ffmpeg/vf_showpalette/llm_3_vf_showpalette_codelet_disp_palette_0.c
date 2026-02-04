#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int x;
extern int y;
extern int i;
extern int j;
extern uint32_t *dst;
extern  int dst_linesize;
extern  uint32_t *pal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern with Indirect Indexing
    // Use pointer arithmetic and strided access by precomputing base offsets and stepping through memory with fixed strides.
    // Introduce indirect access via a lookup table for pal indices (simulating irregular but predictable access).

    int pal_index[256]; // Precomputed palette index mapping: y*16 + x
    for (int idx = 0; idx < 256; idx++)
        pal_index[idx] = idx;

    uint32_t *dst_base = dst;
    for (y = 0; y < 16; y++) {
        int base_offset_y = y * dst_linesize * size;
        int pal_base = y * 16;
        for (x = 0; x < 16; x++) {
            int dst_stride_x = base_offset_y + x * size;
            uint32_t val = pal[pal_index[pal_base + x]]; // Indirect read via lookup
            for (j = 0; j < size; j++) {
                int dst_row = dst_stride_x + j * dst_linesize;
                for (i = 0; i < size; i++) {
                    dst_base[dst_row + i] = val; // Strided write: jumps of dst_linesize per j
                }
            }
        }
    }
}
