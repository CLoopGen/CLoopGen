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
    // Variant 1: Consecutive memory access using local pointers with pre-computed strides
    int32_t *tmp_local = tmp;
    const uint16_t *src_local = src;
    for (i = 0; i < h + 5; i++) {
        const uint16_t *src_row = src_local;
        tmp_local[0] = (src_row[0] + src_row[1]) * 20 - (src_row[-1] + src_row[2]) * 5 + (src_row[-2] + src_row[3]) + pad;
        tmp_local[1] = (src_row[1] + src_row[2]) * 20 - (src_row[0] + src_row[3]) * 5 + (src_row[-1] + src_row[4]) + pad;
        tmp_local += tmpStride;
        src_local += srcStride;
    }
}
