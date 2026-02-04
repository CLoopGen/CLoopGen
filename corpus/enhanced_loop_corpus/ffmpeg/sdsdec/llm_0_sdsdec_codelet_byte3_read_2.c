#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 40; j++) {
        unsigned int sample;
        for (i = j * 3; i < (j + 1) * 3; i += 3) {
            sample = ((unsigned int)src[i + 0] << 25) | ((unsigned int)src[i + 1] << 18) | ((unsigned int)src[i + 2] << 11);
            dst[j] = sample;
        }
    }
}
