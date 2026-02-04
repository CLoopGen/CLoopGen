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
    // Variant 2: Strided memory access pattern using array indexing with explicit stride scaling
    // This variant unrolls the access pattern and uses fixed offsets scaled by a larger step
    // to simulate strided data traversal (e.g., every second row in a larger matrix)
    for (i = 0; i < h + 5; i++) {
        int src_offset = i * srcStride;
        int tmp_offset = i * tmpStride;
        tmp[tmp_offset]     = (src[src_offset] + src[src_offset + 1]) * 20 - 
                             (src[src_offset - 1] + src[src_offset + 2]) * 5 + 
                             (src[src_offset - 2] + src[src_offset + 3]) + pad;
        tmp[tmp_offset + 1] = (src[src_offset + 1] + src[src_offset + 2]) * 20 - 
                             (src[src_offset] + src[src_offset + 3]) * 5 + 
                             (src[src_offset - 1] + src[src_offset + 4]) + pad;
    }
}
