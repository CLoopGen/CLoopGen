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
    tmp += 8;
    src += sstride;
}
}
