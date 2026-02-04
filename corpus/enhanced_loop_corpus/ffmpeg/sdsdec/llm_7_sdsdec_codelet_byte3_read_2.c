#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp[3];
    for (i = 0; i < 120; i += 3) {
        temp[0] = (unsigned int)src[i + 0] << 25;
        temp[1] = (unsigned int)src[i + 1] << 18;
        temp[2] = (unsigned int)src[i + 2] << 11;
        dst[i / 3] = temp[0] | temp[1] | temp[2];
    }
}
