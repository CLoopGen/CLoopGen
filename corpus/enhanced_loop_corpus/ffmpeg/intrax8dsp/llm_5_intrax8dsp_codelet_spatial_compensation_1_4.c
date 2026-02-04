#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        int base_offset = (8 + 8 + 1);
        int limit = 15;
        for (x = 0; x < 8; x++) {
            int addr = 2 * y + x + 2;
            addr = (addr > limit) ? limit : addr;
            dst[x] = src[base_offset + addr];
        }
        dst += stride;
        if (y == 3) continue;
    }
}
