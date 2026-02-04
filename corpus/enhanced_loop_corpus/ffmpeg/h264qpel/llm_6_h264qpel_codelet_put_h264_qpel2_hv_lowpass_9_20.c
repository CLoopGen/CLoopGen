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
        int val0 = (src_local[0] + src_local[1]) * 20;
        int val1 = (src_local[-1] + src_local[2]) * 5;
        int val2 = (src_local[-2] + src_local[3]);
        tmp_local[0] = val0 - val1 + val2 + pad;

        int val3 = (src_local[1] + src_local[2]) * 20;
        int val4 = (src_local[0] + src_local[3]) * 5;
        int val5 = (src_local[-1] + src_local[4]);
        tmp_local[1] = val3 - val4 + val5 + pad;

        tmp_local += tmpStride;
        src_local += srcStride;
    }
}
