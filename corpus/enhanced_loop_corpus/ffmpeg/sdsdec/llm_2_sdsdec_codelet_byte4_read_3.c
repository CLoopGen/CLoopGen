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
        // Reverse access pattern: process elements from end to beginning with same stride
        int rev_i = 119 - i;
        sample = ((unsigned int)src[rev_i - 3] << 25) | ((unsigned int)src[rev_i - 2] << 18) | 
                 ((unsigned int)src[rev_i - 1] << 11) | ((unsigned int)src[rev_i] << 4);
        dst[(119 - i) / 4] = sample;
    }
}
