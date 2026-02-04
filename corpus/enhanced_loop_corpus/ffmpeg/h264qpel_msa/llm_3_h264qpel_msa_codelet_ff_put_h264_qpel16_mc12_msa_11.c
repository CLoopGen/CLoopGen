#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (row = 16; row--;) {
    uint8_t *s = src;
    uint8_t *d = dst;
    for (ptrdiff_t offset = 0; offset < 16; offset += 4) {
        d[offset + 0] = s[(offset + 0) * 2]; 
        d[offset + 1] = s[(offset + 1) * 2]; 
        d[offset + 2] = s[(offset + 2) * 2]; 
        d[offset + 3] = s[(offset + 3) * 2]; 
    }
    src += stride;
    dst += stride;
}
}
