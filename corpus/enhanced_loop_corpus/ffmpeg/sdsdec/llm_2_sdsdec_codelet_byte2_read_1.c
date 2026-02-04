#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 120; i += 4) {
    unsigned int sample1 = ((unsigned int)src[i + 0] << 25) + ((unsigned int)src[i + 1] << 18);
    unsigned int sample2 = ((unsigned int)src[i + 2] << 25) + ((unsigned int)src[i + 3] << 18);
    dst[i / 2 + 0] = sample1;
    dst[i / 2 + 1] = sample2;
}
}
