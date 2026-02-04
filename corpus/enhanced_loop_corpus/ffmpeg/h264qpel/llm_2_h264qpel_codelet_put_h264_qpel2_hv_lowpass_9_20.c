#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Local Stride Simulation
    // Instead of updating src and tmp pointers directly, use index-based access to simulate stride.
    // This changes memory access pattern to be more predictable and enables potential vectorization.
    for (i = 0; i < h + 5; i++) {
        int src_idx = i * srcStride;
        int tmp_idx = i * tmpStride;
        
        tmp[tmp_idx + 0] = (src[src_idx + 0] + src[src_idx + 1]) * 20 
                         - (src[src_idx - 1] + src[src_idx + 2]) * 5 
                         + (src[src_idx - 2] + src[src_idx + 3]) + pad;
                         
        tmp[tmp_idx + 1] = (src[src_idx + 1] + src[src_idx + 2]) * 20 
                         - (src[src_idx + 0] + src[src_idx + 3]) * 5 
                         + (src[src_idx - 1] + src[src_idx + 4]) + pad;
    }
}
