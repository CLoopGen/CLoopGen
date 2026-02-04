#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int b_w;
extern int b_h;
extern int x;
extern int y;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int stride1;
extern int stride2;
extern int a;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int shift = 5;
for (y = 0; y < b_h; y++) {
    for (x = 0; x < b_w; x++) {
        int temp1 = a * src1[x];
        int temp2 = b * src2[x];
        int sum = temp1 + temp2 + 8;
        dst[x] = (sum + (1 << (shift-1))) >> shift;
    }
    src1 += stride1;
    src2 += stride2;
    dst += stride;
}
}
