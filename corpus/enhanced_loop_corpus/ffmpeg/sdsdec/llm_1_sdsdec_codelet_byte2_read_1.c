#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 30; outer++) {
        for (int inner = 0; inner < 4; inner += 2) {
            int i = outer * 4 + inner;
            unsigned int sample = ((unsigned int)src[i + 0] << 25) + ((unsigned int)src[i + 1] << 18);
            dst[i / 2] = sample;
        }
    }
}
