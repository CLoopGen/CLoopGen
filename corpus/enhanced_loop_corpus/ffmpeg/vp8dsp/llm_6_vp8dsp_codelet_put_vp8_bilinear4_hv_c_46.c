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
        uint8_t t0 = (a * src[0] + b * src[1] + 4) >> 3;
        uint8_t t1 = (a * src[1] + b * src[2] + 4) >> 3;
        uint8_t t2 = (a * src[2] + b * src[3] + 4) >> 3;
        uint8_t t3 = (a * src[3] + b * src[4] + 4) >> 3;
        tmp[0] = t0;
        tmp[1] = t1;
        tmp[2] = t2;
        tmp[3] = t3;
        tmp += 4;
        src += sstride;
    }
}
