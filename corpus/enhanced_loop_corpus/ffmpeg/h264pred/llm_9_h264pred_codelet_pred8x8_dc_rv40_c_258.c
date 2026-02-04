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
for (i = 4; i < 6; i++) {
    uint32_t *ptr1 = (uint32_t *)(src + i * stride);
    uint32_t *ptr2 = (uint32_t *)(src + (i + 1) * stride);
    ptr1[0] = dc0;
    ptr1[1] = dc0;
    ptr2[0] = dc0;
    ptr2[1] = dc0;
}
}
