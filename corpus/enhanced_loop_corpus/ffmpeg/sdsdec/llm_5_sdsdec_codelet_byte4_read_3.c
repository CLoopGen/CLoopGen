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
        unsigned int sample = 0;
        if (src[i + 0] >= 128) continue;
        if (src[i + 1] >= 128) break;
        sample |= ((unsigned int)src[i + 0] << 25);
        sample |= ((unsigned int)src[i + 1] << 18);
        sample |= ((unsigned int)src[i + 2] << 11);
        sample |= ((unsigned int)src[i + 3] << 4);
        dst[i / 4] = sample;
    }
}
