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
    for (y = 0; y <= h; y++) {
        for (x = 0; x < 16; x++) {
            int index = x + 1;
            if (index >= 16) continue;
            tmp[x] = (a * src[x] + b * src[index] + 4) >> 3;
        }
        tmp += 16;
        src += sstride;
    }
}
