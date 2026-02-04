#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint32_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp[4];
    for (i = 0; i < 4; i++)
        temp[i] = ((src[i] << 16) | (src[i] >> 16)) ^ src[7 - i];
    for (i = 0; i < 4; i++)
        src[i] = temp[i];
}
