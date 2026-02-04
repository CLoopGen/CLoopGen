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
for (y = 0; y < h + 2; y += 2) {
    for (x = 0; x < 8; x++) {
        tmp[x]           = (a * src[x] + b * src[x + 1] + 4) >> 3;
        tmp[x + 8]       = (a * src[x + 16] + b * src[x + 17] + 4) >> 3;
    }
    if (y + 1 < h + 2) {
        tmp += 16;
        src += sstride;
    }
    tmp += 16;
    src += sstride;
}
}
