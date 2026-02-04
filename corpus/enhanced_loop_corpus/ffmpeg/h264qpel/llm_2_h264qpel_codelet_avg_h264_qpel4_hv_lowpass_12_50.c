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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled in a linear fashion
    // Instead of using array indexing with negative offsets, we pre-adjust the source pointer to create a windowed view.
    // This improves spatial locality and enables better vectorization.

    uint16_t *src_base = src - 2;  // Align base pointer to cover src[-2] as first element
    for (i = 0; i < h + 5; i++) {
        tmp[0] = (src_base[2] + src_base[3]) * 20 - (src_base[1] + src_base[4]) * 5 + (src_base[0] + src_base[5]) + pad;
        tmp[1] = (src_base[3] + src_base[4]) * 20 - (src_base[2] + src_base[5]) * 5 + (src_base[1] + src_base[6]) + pad;
        tmp[2] = (src_base[4] + src_base[5]) * 20 - (src_base[3] + src_base[6]) * 5 + (src_base[2] + src_base[7]) + pad;
        tmp[3] = (src_base[5] + src_base[6]) * 20 - (src_base[4] + src_base[7]) * 5 + (src_base[3] + src_base[8]) + pad;

        tmp += tmpStride;
        src_base += srcStride;  // Move the base window forward
    }
}
