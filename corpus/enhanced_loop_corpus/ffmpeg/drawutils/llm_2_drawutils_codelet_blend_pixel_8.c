#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *mask;
extern int mask_linesize;
extern int l2depth;
extern unsigned int w;
extern unsigned int h;
extern unsigned int xm0;
extern unsigned int xm;
extern unsigned int x;
extern unsigned int y;
extern unsigned int t;
extern unsigned int xmshf;
extern unsigned int xmmod;
extern unsigned int mbits;
extern unsigned int mmult;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access with Prefetching and Reordered Operations
    uint8_t *mask_row = mask;
    for (y = 0; y < h; y++) {
        xm = xm0;
        unsigned int temp_sum = 0;
        for (x = 0; x < w; x++) {
            // Force consecutive access by precomputing index and using local accumulation
            size_t byte_index = xm >> xmshf;
            size_t bit_offset = (~xm & xmmod) << l2depth;
            temp_sum += ((mask_row[byte_index] >> bit_offset) & mbits) * mmult;
            xm++;
        }
        t += temp_sum;  // Accumulate once per row
        mask_row += mask_linesize;  // Move to next row
    }
}
