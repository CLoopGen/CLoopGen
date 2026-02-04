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
    if (b_h > 0) {
        for (int y = 0; y < b_h; y += 2) {
            // Unroll two iterations of the original loop
            *(uint32_t *)&dst[0 + y * stride] = color4;
            *(uint32_t *)&dst[4 + y * stride] = color4;

            if (y + 1 < b_h) {
                *(uint32_t *)&dst[0 + (y + 1) * stride] = color4;
                *(uint32_t *)&dst[4 + (y + 1) * stride] = color4;
            }
        }
    }
}
