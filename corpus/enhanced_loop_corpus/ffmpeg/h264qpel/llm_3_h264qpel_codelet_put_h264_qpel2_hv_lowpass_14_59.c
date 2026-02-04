#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with offset indexing to simulate irregular but predictable pattern
    // Simulate a more scattered access by introducing a base index and accessing via variable offsets
    ptrdiff_t src_idx = 0;
    ptrdiff_t tmp_idx = 0;
    for (i = 0; i < h + 5; i++) {
        // Use strided index arithmetic instead of pointer arithmetic
        tmp[tmp_idx + 0] = (src[src_idx - 0] + src[src_idx + 1]) * 20 
                         - (src[src_idx - 1] + src[src_idx + 2]) * 5 
                         + (src[src_idx - 2] + src[src_idx + 3]) + pad;
        tmp[tmp_idx + 1] = (src[src_idx + 1] + src[src_idx + 2]) * 20 
                         - (src[src_idx + 0] + src[src_idx + 3]) * 5 
                         + (src[src_idx - 1] + src[src_idx + 4]) + pad;
        tmp_idx += tmpStride;
        src_idx += srcStride;
    }
}
