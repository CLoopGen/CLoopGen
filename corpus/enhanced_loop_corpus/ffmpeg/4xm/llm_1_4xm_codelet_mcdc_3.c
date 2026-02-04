#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern int h;
extern int stride;
extern int scale;
extern unsigned int dc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < 1; j++) {  // Degenerate inner loop with fixed iteration
            dst[0] = scale * src[0] + dc;
            if (scale)
                src += stride;
        }
        dst += stride;
    }
}
