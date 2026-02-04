#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern unsigned int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        uint32_t *base1 = (uint32_t *)(src + (2*i+0) * stride);
        uint32_t *base2 = (uint32_t *)(src + (2*i+1) * stride);
        base1[0] = base1[1] = dc0;
        base2[0] = base2[1] = dc0;
    }
}
