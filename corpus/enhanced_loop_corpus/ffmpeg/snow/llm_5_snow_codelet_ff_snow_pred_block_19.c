#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_h;
extern int y;
extern  unsigned int color4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < b_h; y++) {
        uint8_t *base = dst + y * stride;
        int offset = 0;
        for (int step = 0; step < 8; step++) {
            if ((y + step) % 2 == 0) {
                *(uint32_t *)(base + offset) = color4;
            } else {
                *(uint32_t *)(base + offset + 4) = color4;
            }
            offset += 4;
            if (offset > 28) break;
        }
    }
}
