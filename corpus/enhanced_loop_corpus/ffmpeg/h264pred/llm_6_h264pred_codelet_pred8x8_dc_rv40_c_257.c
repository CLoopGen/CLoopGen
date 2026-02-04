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
    uint32_t temp1, temp2;
    for (i = 0; i < 4; i++) {
        temp1 = dc0 + i;
        temp2 = dc0 ^ i;
        ((uint32_t *)(src + i * stride))[0] = temp1;
        ((uint32_t *)(src + i * stride))[1] = temp2;
    }
}
