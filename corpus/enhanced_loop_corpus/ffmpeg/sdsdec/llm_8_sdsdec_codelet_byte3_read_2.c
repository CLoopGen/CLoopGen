#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 120; i += 6) {
    unsigned int sample1, sample2;
    sample1 = ((unsigned int)src[i + 0] << 25) | ((unsigned int)src[i + 1] << 18) | ((unsigned int)src[i + 2] << 11);
    sample2 = ((unsigned int)src[i + 3] << 25) | ((unsigned int)src[i + 4] << 18) | ((unsigned int)src[i + 5] << 11);
    dst[i / 3] = sample1;
    dst[i / 3 + 1] = sample2;
}
}
