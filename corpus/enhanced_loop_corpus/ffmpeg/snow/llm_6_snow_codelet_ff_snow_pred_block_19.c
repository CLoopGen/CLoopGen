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
    uint32_t *base_ptr;
    for (y = 0; y < b_h; y++) {
        base_ptr = (uint32_t *)&dst[y * stride];
        base_ptr[0] = color4;
        base_ptr[1] = color4;
        base_ptr[2] = color4;
        base_ptr[3] = color4;
        base_ptr[4] = color4;
        base_ptr[5] = color4;
        base_ptr[6] = color4;
        base_ptr[7] = color4;
    }
}
