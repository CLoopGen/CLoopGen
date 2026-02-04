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
        uint32_t *row1 = (uint32_t *)(src + i * stride);
        uint32_t *row2 = (uint32_t *)(src + (i + 4) * stride);
        row1[0] = row1[1] = dc0;
        row2[0] = row2[1] = dc0;
    }
}
