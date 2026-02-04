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
    ptrdiff_t offset = 0;
    for (i = 0; i < h; i++) {
        dst[offset] = ((((A * src[offset])) + 32) >> 6);
        offset += stride;
    }
}
