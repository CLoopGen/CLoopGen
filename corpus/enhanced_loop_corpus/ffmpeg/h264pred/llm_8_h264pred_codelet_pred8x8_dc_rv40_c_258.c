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
for (i = 4; i < 12; i += 2) {
    uint32_t *base = (uint32_t *)(src + i * stride);
    base[0] = dc0;
    base[1] = dc0;
    base[2] = dc0;
    base[3] = dc0;
}
}
