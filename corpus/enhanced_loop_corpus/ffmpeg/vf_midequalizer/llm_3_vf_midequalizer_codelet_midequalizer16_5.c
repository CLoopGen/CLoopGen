#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t linesize1;
extern ptrdiff_t dlinesize;
extern int w0;
extern int h0;
extern unsigned int *cchange;
extern  uint16_t *i;
extern uint16_t *d;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing
    // This variant accesses array `i` in a strided pattern (every 2nd element), then maps through `cchange`.
    // It simulates scenarios where input data is accessed non-consecutively due to subsampling or filtering.
    // The output is written sparsely at first, then compacted (here simplified to full write-back).
    uint16_t *d_ptr = d;
    uint16_t *i_ptr = i;
    int stride = 2;
    int effective_w = (w0 + stride - 1) / stride;

    for (y = 0; y < h0; y++) {
        for (x = 0; x < effective_w; x++) {
            int src_idx = x * stride;
            if (src_idx < w0) {
                d_ptr[src_idx] = cchange[i_ptr[src_idx]];
                if (src_idx + 1 < w0) {
                    d_ptr[src_idx + 1] = cchange[i_ptr[src_idx + 1]]; // Fill adjacent for continuity
                }
            }
        }
        d_ptr = (uint16_t *)((char *)d_ptr + dlinesize);
        i_ptr = (uint16_t *)((char *)i_ptr + linesize1);
    }
}
