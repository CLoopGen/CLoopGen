#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int x;
extern int unaligned_w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    int outer_iter = unaligned_w / 4;
    int remainder = unaligned_w % 4;

    for (i = 0; i < outer_iter; i++) {
        *dst++ = *src1++ - *src2++;
        *dst++ = *src1++ - *src2++;
        *dst++ = *src1++ - *src2++;
        *dst++ = *src1++ - *src2++;
    }

    for (j = 0; j < remainder; j++) {
        *dst++ = *src1++ - *src2++;
    }
}
