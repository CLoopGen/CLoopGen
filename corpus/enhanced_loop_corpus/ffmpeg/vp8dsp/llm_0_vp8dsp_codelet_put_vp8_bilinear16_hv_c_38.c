#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t sstride;
extern int h;
extern int a;
extern int b;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h + 1; y++) {
    x = 0;
    tmp[0] = (a * src[0] + b * src[1] + 4) >> 3;
    x = 1;
    tmp[1] = (a * src[1] + b * src[2] + 4) >> 3;
    x = 2;
    tmp[2] = (a * src[2] + b * src[3] + 4) >> 3;
    x = 3;
    tmp[3] = (a * src[3] + b * src[4] + 4) >> 3;
    x = 4;
    tmp[4] = (a * src[4] + b * src[5] + 4) >> 3;
    x = 5;
    tmp[5] = (a * src[5] + b * src[6] + 4) >> 3;
    x = 6;
    tmp[6] = (a * src[6] + b * src[7] + 4) >> 3;
    x = 7;
    tmp[7] = (a * src[7] + b * src[8] + 4) >> 3;
    x = 8;
    tmp[8] = (a * src[8] + b * src[9] + 4) >> 3;
    x = 9;
    tmp[9] = (a * src[9] + b * src[10] + 4) >> 3;
    x = 10;
    tmp[10] = (a * src[10] + b * src[11] + 4) >> 3;
    x = 11;
    tmp[11] = (a * src[11] + b * src[12] + 4) >> 3;
    x = 12;
    tmp[12] = (a * src[12] + b * src[13] + 4) >> 3;
    x = 13;
    tmp[13] = (a * src[13] + b * src[14] + 4) >> 3;
    x = 14;
    tmp[14] = (a * src[14] + b * src[15] + 4) >> 3;
    x = 15;
    tmp[15] = (a * src[15] + b * src[16] + 4) >> 3;
    tmp += 16;
    src += sstride;
}
}
