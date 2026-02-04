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
        for (x = 0; x < 8; x++) {
            if (x % 2 == 0)
                tmp[x] = (a * src[x] + b * src[x + 1] + 4) >> 3;
            else
                tmp[x] = (b * src[x] + a * src[x + 1] + 4) >> 3;
        }
        tmp += 8;
        src += sstride;
    }
}
