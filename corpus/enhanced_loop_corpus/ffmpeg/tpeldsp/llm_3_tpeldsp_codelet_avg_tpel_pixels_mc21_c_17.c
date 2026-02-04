#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - traverse columns first, then rows (column-major traversal)
    // This changes access pattern from row-wise to column-wise for both src and dst
    for (j = 0; j < width; j++) {
        for (i = 0; i < height; i++) {
            int idx = i * stride + j;
            int src_idx = idx;
            dst[idx] = (dst[idx] + 
                       (((3 * src[src_idx] + 
                          4 * src[src_idx + 1] + 
                          2 * src[src_idx + stride] + 
                          3 * src[src_idx + stride + 1] + 6) * 2731) >> 15) + 1) >> 1;
        }
    }
    // Adjust global pointers as in original: advance src and dst by total frame size
    src += height * stride;
    dst += height * stride;
}
