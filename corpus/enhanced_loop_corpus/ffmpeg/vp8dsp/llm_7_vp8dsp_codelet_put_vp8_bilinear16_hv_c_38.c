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
        uint8_t local_tmp[16];
        for (x = 0; x < 16; x++) {
            local_tmp[x] = (a * src[x] + b * src[x + 1] + 4) >> 3;
        }
        for (x = 0; x < 16; x++) {
            tmp[x] = local_tmp[(x + 8) & 15]; // Introduce WAR dependency via reorder
        }
        tmp += 16;
        src += sstride;
    }
}
