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
extern  uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using index array offsets (simulating non-unit stride pattern)
    // We simulate a strided access by precomputing effective indices relative to base pointers
    ptrdiff_t src_offset = 0;
    ptrdiff_t tmp_offset = 0;
    for (i = 0; i < h + 5; i++) {
        // Define local offsets for current row
        const ptrdiff_t s_idx = src_offset;
        const ptrdiff_t t_idx = tmp_offset;

        tmp[t_idx + 0] = (src[s_idx + 0] + src[s_idx + 1]) * 20 
                       - (src[s_idx - 1] + src[s_idx + 2]) * 5 
                       + (src[s_idx - 2] + src[s_idx + 3]) + pad;
        tmp[t_idx + 1] = (src[s_idx + 1] + src[s_idx + 2]) * 20 
                       - (src[s_idx + 0] + src[s_idx + 3]) * 5 
                       + (src[s_idx - 1] + src[s_idx + 4]) + pad;
        tmp[t_idx + 2] = (src[s_idx + 2] + src[s_idx + 3]) * 20 
                       - (src[s_idx + 1] + src[s_idx + 4]) * 5 
                       + (src[s_idx + 0] + src[s_idx + 5]) + pad;
        tmp[t_idx + 3] = (src[s_idx + 3] + src[s_idx + 4]) * 20 
                       - (src[s_idx + 2] + src[s_idx + 5]) * 5 
                       + (src[s_idx + 1] + src[s_idx + 6]) + pad;
        tmp[t_idx + 4] = (src[s_idx + 4] + src[s_idx + 5]) * 20 
                       - (src[s_idx + 3] + src[s_idx + 6]) * 5 
                       + (src[s_idx + 2] + src[s_idx + 7]) + pad;
        tmp[t_idx + 5] = (src[s_idx + 5] + src[s_idx + 6]) * 20 
                       - (src[s_idx + 4] + src[s_idx + 7]) * 5 
                       + (src[s_idx + 3] + src[s_idx + 8]) + pad;
        tmp[t_idx + 6] = (src[s_idx + 6] + src[s_idx + 7]) * 20 
                       - (src[s_idx + 5] + src[s_idx + 8]) * 5 
                       + (src[s_idx + 4] + src[s_idx + 9]) + pad;
        tmp[t_idx + 7] = (src[s_idx + 7] + src[s_idx + 8]) * 20 
                       - (src[s_idx + 6] + src[s_idx + 9]) * 5 
                       + (src[s_idx + 5] + src[s_idx + 10]) + pad;

        // Advance offsets by strides
        src_offset += srcStride;
        tmp_offset += tmpStride;
    }
}
