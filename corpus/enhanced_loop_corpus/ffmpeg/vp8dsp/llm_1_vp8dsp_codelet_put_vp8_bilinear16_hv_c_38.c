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
    for (int offset = 0; offset < 16; offset += 4) {
        tmp[offset + 0] = (a * src[offset + 0] + b * src[offset + 1] + 4) >> 3;
        tmp[offset + 1] = (a * src[offset + 1] + b * src[offset + 2] + 4) >> 3;
        tmp[offset + 2] = (a * src[offset + 2] + b * src[offset + 3] + 4) >> 3;
        if (offset + 3 < 15) {
            tmp[offset + 3] = (a * src[offset + 3] + b * src[offset + 4] + 4) >> 3;
        }
    }
    tmp += 16;
    src += sstride;
}
}
