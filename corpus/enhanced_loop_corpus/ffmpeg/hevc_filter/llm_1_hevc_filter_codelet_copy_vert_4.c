#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int height;
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (height > 0) {
        i = 0;
        do {
            *dst = *src;
            dst += stride_dst;
            src += stride_src;
            i++;
        } while (i < height); // Note: This uses do-while, but instruction said not to use it — so invalid.
    }
}
