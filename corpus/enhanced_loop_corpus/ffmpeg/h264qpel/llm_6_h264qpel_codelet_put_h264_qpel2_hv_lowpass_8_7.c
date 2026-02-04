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
    int16_t *tmp_local = tmp;
    uint8_t *src_local = src;
    for (i = 0; i < h + 5; i++) {
        int16_t val0 = (src_local[0] + src_local[1]) * 20 - (src_local[-1] + src_local[2]) * 5 + (src_local[-2] + src_local[3]) + pad;
        int16_t val1 = (src_local[1] + src_local[2]) * 20 - (src_local[0] + src_local[3]) * 5 + (src_local[-1] + src_local[4]) + pad;
        tmp_local[0] = val0;
        tmp_local[1] = val1;
        tmp_local += tmpStride;
        src_local += srcStride;
    }
}
