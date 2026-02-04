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
    for (x = 0; x < 16; x += 2) {
        tmp[x]     = (a * src[x]     + b * src[x + 1]     + 4) >> 3;
        tmp[x + 1] = (a * src[x + 1] + b * src[x + 2]     + 4) >> 3;
    }
    tmp += 16;
    src += sstride;
}
}
