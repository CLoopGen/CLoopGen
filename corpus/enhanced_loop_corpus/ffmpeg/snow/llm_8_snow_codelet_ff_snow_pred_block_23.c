#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_w;
extern int b_h;
extern int x;
extern int y;
extern  unsigned int color;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < b_h; y += 2) {
        for (x = 0; x < b_w; x += 2) {
            uint8_t val = color;
            dst[x + y * stride] = val;
            if (x + 1 < b_w) dst[x + 1 + y * stride] = val;
            if (y + 1 < b_h) dst[x + (y + 1) * stride] = val;
            if (x + 1 < b_w && y + 1 < b_h) dst[x + 1 + (y + 1) * stride] = val;
        }
    }
}
