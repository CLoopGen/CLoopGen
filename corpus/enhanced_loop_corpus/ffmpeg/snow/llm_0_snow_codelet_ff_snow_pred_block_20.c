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
    for (int y = 0; y < b_h; y++) {
        for (int x = 0; x < 4; x++) {
            *(uint32_t *)&dst[x * 4 + y * stride] = color4;
        }
    }
}
