#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 84 - 4; i += 4) {
        dst[i]     = src[i + 4];
        dst[i + 2] = src[i + 6];
    }
}
