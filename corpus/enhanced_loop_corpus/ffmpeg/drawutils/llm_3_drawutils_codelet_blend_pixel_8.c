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
    // Variant 2: Strided Memory Access with Transposed Iteration (Column-Major Scan)
    uint8_t *base_mask = mask;
    for (x = 0; x < w; x++) {
        unsigned int col_sum = 0;
        xm = xm0 + x;  // Start xm at initial offset plus column offset
        for (y = 0; y < h; y++) {
            // Strided access: each iteration jumps by mask_linesize in memory
            size_t byte_index = xm >> xmshf;
            size_t bit_offset = (~xm & xmmod) << l2depth;
            uint8_t *current_mask = base_mask + y * mask_linesize;
            col_sum += ((current_mask[byte_index] >> bit_offset) & mbits) * mmult;
            xm += w;  // Stride by width to simulate transposed traversal
        }
        t += col_sum;
    }
}
