#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 30; j++) {
        unsigned int sample;
        for (int k = 0; k < 1; k++) {  // Artificially nested inner loop with single iteration
            int idx = j * 4;
            sample = ((unsigned int)src[idx + 0] << 25) | 
                     ((unsigned int)src[idx + 1] << 18) | 
                     ((unsigned int)src[idx + 2] << 11) | 
                     ((unsigned int)src[idx + 3] << 4);
            dst[j] = sample;
        }
    }
}
