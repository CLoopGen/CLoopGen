#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp;
    for (i = 0; i < 120; i += 4) {
        temp = ((unsigned int)src[i + 3] << 4);
        temp |= ((unsigned int)src[i + 2] << 11);
        temp |= ((unsigned int)src[i + 1] << 18);
        temp |= ((unsigned int)src[i + 0] << 25);
        dst[i / 4] = temp;
    }
}
