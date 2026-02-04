#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 240; i += 8) {
    unsigned int sample1, sample2;
    sample1 = ((unsigned int)src[i + 0] << 25) | ((unsigned int)src[i + 1] << 18) | ((unsigned int)src[i + 2] << 11) | ((unsigned int)src[i + 3] << 4);
    sample2 = ((unsigned int)src[i + 4] << 25) | ((unsigned int)src[i + 5] << 18) | ((unsigned int)src[i + 6] << 11) | ((unsigned int)src[i + 7] << 4);
    dst[i / 4 + 0] = sample1;
    dst[i / 4 + 1] = sample2;
}
}
