#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 120; i += 2) {
        if ((src[i] & 0x80) == 0) {
            unsigned int sample = ((unsigned int)src[i] << 25) | ((unsigned int)src[i + 1] << 18);
            dst[i / 2] = sample;
        } else {
            dst[i / 2] = 0;
        }
    }
}
