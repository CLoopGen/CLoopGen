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
    // Variant 2: Strided memory access with increasing stride to simulate non-unit stride over source
    // Simulate processing every other row in source but scaled — here we modify access pattern to use a fixed stride multiplier
    const int stride_factor = 2;
    ptrdiff_t effective_src_linesize = src_linesize * stride_factor;
    for (y = 0; y < h; y++, dst += dst_linesize, src += 4) {
        for (x = 0; x < w; x++) {
            // Now accessing source with strided offset: effectively sampling less frequently
            ptrdiff_t offset = (x * effective_src_linesize) / stride_factor; // Maintain alignment
            *((uint32_t *)(dst + 4 * x)) = *((uint32_t *)(src + offset));
        }
    }
}
