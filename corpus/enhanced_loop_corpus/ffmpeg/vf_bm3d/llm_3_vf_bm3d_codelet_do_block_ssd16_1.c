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
    // Variant 2: Strided memory access with reversed traversal order (reverse column iteration)
    // This changes access pattern to go from high to low index, creating backward strided behavior
    for (y = 0; y < block_size; y++) {
        for (x = block_size - 1; x >= 0; x--) {
            double temp = refp[x] - srcp[x];
            dist += temp * temp;
        }
        srcp += src_stride / 2;
        refp += src_stride / 2;
    }
}
