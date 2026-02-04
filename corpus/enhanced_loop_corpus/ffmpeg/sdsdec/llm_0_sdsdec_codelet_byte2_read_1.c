#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 60; j++) {
        unsigned int sample = ((unsigned int)src[2*j + 0] << 25) + ((unsigned int)src[2*j + 1] << 18);
        dst[j] = sample;
    }
}
