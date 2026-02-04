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
        unsigned int sample;
        if ((i % 16) < 8) {
            sample = ((unsigned int)src[i + 0] << 25) | ((unsigned int)src[i + 1] << 18) | 
                     ((unsigned int)src[i + 2] << 11) | ((unsigned int)src[i + 3] << 4);
        } else {
            sample = ((unsigned int)src[i + 0] << 24) | ((unsigned int)src[i + 1] << 17) | 
                     ((unsigned int)src[i + 2] << 10) | ((unsigned int)src[i + 3] << 3);
        }
        dst[i / 4] = sample;
    }
}
