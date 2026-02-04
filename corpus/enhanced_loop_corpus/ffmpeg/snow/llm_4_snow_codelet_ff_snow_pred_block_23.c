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
for (y = 0; y < b_h; y++) {
    if (y % 2 == 0) {
        for (x = 0; x < b_w; x++) {
            dst[x + y * stride] = color;
        }
    } else {
        for (x = b_w - 1; x >= 0; x--) {
            dst[x + y * stride] = color;
        }
    }
}
}
