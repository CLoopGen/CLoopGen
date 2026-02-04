#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_stride;
extern  uint8_t *srcp;
extern  uint8_t *refp;
extern  int block_size;
extern double dist;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with vertical traversal (column-major style)
    // Instead of processing row-by-row, process column-by-column to simulate transposed access pattern
    for (x = 0; x < block_size; x++) {
        uint8_t *src_col = srcp + x;
        uint8_t *ref_col = refp + x;
        for (y = 0; y < block_size; y++) {
            double temp = ref_col[0] - src_col[0];
            dist += temp * temp;
            src_col += src_stride;
            ref_col += src_stride;
        }
    }
    // Update srcp and refp to point past the processed block (maintain consistency with original side effects)
    srcp += block_size * src_stride;
    refp += block_size * src_stride;
}
