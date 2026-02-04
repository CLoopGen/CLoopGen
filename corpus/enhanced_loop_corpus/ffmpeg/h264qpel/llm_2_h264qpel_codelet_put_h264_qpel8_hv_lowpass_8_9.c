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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    int16_t *tmp_ptr = tmp;
    uint8_t *src_ptr = src;
    for (i = 0; i < h + 5; i++) {
        const uint8_t *s = src_ptr;
        int16_t *t = tmp_ptr;

        t[0] = (s[0] + s[1]) * 20 - (s[-1] + s[2]) * 5 + (s[-2] + s[3]) + pad;
        t[1] = (s[1] + s[2]) * 20 - (s[0] + s[3]) * 5 + (s[-1] + s[4]) + pad;
        t[2] = (s[2] + s[3]) * 20 - (s[1] + s[4]) * 5 + (s[0] + s[5]) + pad;
        t[3] = (s[3] + s[4]) * 20 - (s[2] + s[5]) * 5 + (s[1] + s[6]) + pad;
        t[4] = (s[4] + s[5]) * 20 - (s[3] + s[6]) * 5 + (s[2] + s[7]) + pad;
        t[5] = (s[5] + s[6]) * 20 - (s[4] + s[7]) * 5 + (s[3] + s[8]) + pad;
        t[6] = (s[6] + s[7]) * 20 - (s[5] + s[8]) * 5 + (s[4] + s[9]) + pad;
        t[7] = (s[7] + s[8]) * 20 - (s[6] + s[9]) * 5 + (s[5] + s[10]) + pad;

        tmp_ptr += tmpStride;
        src_ptr += srcStride;
    }
    tmp = tmp_ptr;
    src = src_ptr;
}
