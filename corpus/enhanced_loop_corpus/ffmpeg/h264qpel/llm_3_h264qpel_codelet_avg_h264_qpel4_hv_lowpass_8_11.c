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
    ptrdiff_t *src_indices = (ptrdiff_t[]){-2, -1, 0, 1, 2, 3, 4, 5, 6};
    ptrdiff_t *tmp_indices = (ptrdiff_t[]){0, 1, 2, 3};

    for (i = 0; i < h + 5; i++) {
        tmp[tmp_indices[0]] = (src[src_indices[2]] + src[src_indices[3]]) * 20 - 
                              (src[src_indices[1]] + src[src_indices[4]]) * 5 + 
                              (src[src_indices[0]] + src[src_indices[5]]) + pad;
        tmp[tmp_indices[1]] = (src[src_indices[3]] + src[src_indices[4]]) * 20 - 
                              (src[src_indices[2]] + src[src_indices[5]]) * 5 + 
                              (src[src_indices[1]] + src[src_indices[6]]) + pad;
        tmp[tmp_indices[2]] = (src[src_indices[4]] + src[src_indices[5]]) * 20 - 
                              (src[src_indices[3]] + src[src_indices[6]]) * 5 + 
                              (src[src_indices[2]] + src[src_indices[7]]) + pad;
        tmp[tmp_indices[3]] = (src[src_indices[5]] + src[src_indices[6]]) * 20 - 
                              (src[src_indices[4]] + src[src_indices[7]]) * 5 + 
                              (src[src_indices[3]] + src[src_indices[8]]) + pad;

        tmp += tmpStride;
        src += srcStride;
    }
}
