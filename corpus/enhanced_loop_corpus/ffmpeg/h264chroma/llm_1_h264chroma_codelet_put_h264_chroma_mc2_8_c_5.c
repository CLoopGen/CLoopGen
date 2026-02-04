#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (h > 0) {
    for (i = 0; i < h; i++) {
        dst[0] = (((A * src[0]) + 32) >> 6);
        dst[1] = (((A * src[1]) + 32) >> 6);
        if (i == 0) {
            i++;  // Skip next iteration index if we handle two rows here
            if (i < h) {
                dst += stride;
                src += stride;
                dst[0] = (((A * src[0]) + 32) >> 6);
                dst[1] = (((A * src[1]) + 32) >> 6);
            }
        }
        dst += stride;
        src += stride;
    }
}
}
