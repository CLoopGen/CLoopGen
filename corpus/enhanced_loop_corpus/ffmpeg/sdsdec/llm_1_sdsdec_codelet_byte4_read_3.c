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
        unsigned int sample0, sample1, sample2, sample3;
        int base = outer * 16;
        if (base + 15 < 120) {
            for (int inner = 0; inner < 4; inner++) {
                int offset = base + inner * 4;
                unsigned int sample = ((unsigned int)src[offset + 0] << 25) | 
                                      ((unsigned int)src[offset + 1] << 18) | 
                                      ((unsigned int)src[offset + 2] << 11) | 
                                      ((unsigned int)src[offset + 3] << 4);
                dst[outer * 4 + inner] = sample;
            }
        }
    }
}
