#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 60; i += 3) {
    unsigned int sample;
    sample = ((unsigned int)src[i + 0] << 27) | ((unsigned int)src[i + 1] << 19) | ((unsigned int)src[i + 2] << 12) |
             ((unsigned int)src[i + 0] >> 5);
    dst[i / 3] = sample ^ (sample >> 16);
}
}
