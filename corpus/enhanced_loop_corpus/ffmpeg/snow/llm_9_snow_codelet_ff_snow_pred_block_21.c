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
    for (y = 0; y < b_h * 2; y++) {
        int effective_y = y >> 1;
        int base_offset = effective_y * stride;
        *(uint32_t *)&dst[(y & 1 ? 4 : 0) + base_offset] = color4;
    }
}
