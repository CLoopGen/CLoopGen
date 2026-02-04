#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint32_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    src[i] ^= ((src[i] << 16) | (src[i] >> 16)) ^ ((src[7 - i] << 8) & 0xFF00FF00);
    src[i] = (src[i] << 1) | (src[i] >> 31);
}
}
