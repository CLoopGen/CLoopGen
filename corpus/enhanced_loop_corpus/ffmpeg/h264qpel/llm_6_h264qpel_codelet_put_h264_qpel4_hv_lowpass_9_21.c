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
    int16_t *tmp_local = tmp;
    uint16_t *src_local = src;
    for (i = 0; i < h + 5; i++) {
        int16_t t0, t1, t2, t3;
        t0 = (src_local[0] + src_local[1]) * 20 - (src_local[-1] + src_local[2]) * 5 + (src_local[-2] + src_local[3]) + pad;
        t1 = (src_local[1] + src_local[2]) * 20 - (src_local[0] + src_local[3]) * 5 + (src_local[-1] + src_local[4]) + pad;
        t2 = (src_local[2] + src_local[3]) * 20 - (src_local[1] + src_local[4]) * 5 + (src_local[0] + src_local[5]) + pad;
        t3 = (src_local[3] + src_local[4]) * 20 - (src_local[2] + src_local[5]) * 5 + (src_local[1] + src_local[6]) + pad;
        tmp_local[0] = t0;
        tmp_local[1] = t1;
        tmp_local[2] = t2;
        tmp_local[3] = t3;
        tmp_local += tmpStride;
        src_local += srcStride;
    }
}
