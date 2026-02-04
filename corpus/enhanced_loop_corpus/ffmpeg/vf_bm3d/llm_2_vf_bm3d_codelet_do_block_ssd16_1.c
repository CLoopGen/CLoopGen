#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_stride;
extern  uint16_t *srcp;
extern  uint16_t *refp;
extern  int block_size;
extern double dist;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and accessing elements in a linear fashion
    // We assume block_size is even for simplicity in unrolling by 2
    for (y = 0; y < block_size; y++) {
        const uint16_t *src_line = srcp;
        const uint16_t *ref_line = refp;
        for (x = 0; x < block_size - 1; x += 2) {
            double temp1 = ref_line[x] - src_line[x];
            double temp2 = ref_line[x+1] - src_line[x+1];
            dist += temp1 * temp1 + temp2 * temp2;
        }
        // Handle odd-sized blocks
        if (x == block_size - 1) {
            double temp = ref_line[x] - src_line[x];
            dist += temp * temp;
        }
        srcp += src_stride / 2;
        refp += src_stride / 2;
    }
}
