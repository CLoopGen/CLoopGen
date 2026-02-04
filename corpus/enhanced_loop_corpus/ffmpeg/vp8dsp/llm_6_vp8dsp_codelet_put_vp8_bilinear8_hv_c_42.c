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
    uint8_t temp_accum[8];
    for (x = 0; x < 8; x++) {
        int val = (a * src[x] + b * src[x + 1] + 4) >> 3;
        temp_accum[x] = (val > 255) ? 255 : (val < 0) ? 0 : val;
    }
    for (x = 0; x < 8; x++)
        tmp[x] = temp_accum[x];
    tmp += 8;
    src += sstride;
}
}
