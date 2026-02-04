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
for (y = 0; y < h + 1; y += 2) {
    if (y + 1 < h + 1) {
        for (x = 0; x < 4; x++) {
            tmp[x] = (a * src[x] + b * src[x + 1] + 4) >> 3;
            tmp[4 + x] = (a * (src + sstride)[x] + b * (src + sstride)[x + 1] + 4) >> 3;
        }
        tmp += 8;
        src += 2 * sstride;
    } else {
        for (x = 0; x < 4; x++)
            tmp[x] = (a * src[x] + b * src[x + 1] + 4) >> 3;
        tmp += 4;
        src += sstride;
    }
}
}
