#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_dst[60];
    for (i = 0; i < 120; i += 2) {
        unsigned int sample = ((unsigned int)src[i + 1] << 25) + ((unsigned int)src[i + 0] << 18);
        temp_dst[i / 2] = sample;
    }
    for (i = 0; i < 60; i++) {
        dst[i] = temp_dst[i];
    }
}
