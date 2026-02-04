#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 120; i += 3) {
        unsigned int sample;
        // Reverse access pattern: process elements from the end with same stride
        int rev_i = 119 - i; // creates a strided reverse access
        sample = ((unsigned int)src[rev_i - 2] << 25) | ((unsigned int)src[rev_i - 1] << 18) | ((unsigned int)src[rev_i] << 11);
        dst[(119 - rev_i) / 3] = sample;
    }
}
