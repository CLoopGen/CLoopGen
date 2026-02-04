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
    for (i = 0; i < 16; i += 2) {
        uint32_t *row = (uint32_t *)(src + i * stride);
        row[0] = row[1] = dc0;
        row[2] = row[3] = dc0;
    }
}
