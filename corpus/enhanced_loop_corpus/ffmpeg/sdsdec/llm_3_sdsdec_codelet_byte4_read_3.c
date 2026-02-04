#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint32_t *dst;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Strided memory access with gap: read every 8th byte, but still process 4 per iteration
    for (i = 0; i < 240; i += 8) {
        if (i / 2 >= 120) break;
        unsigned int sample;
        sample = ((unsigned int)src[i / 2 + 0] << 25) | ((unsigned int)src[i / 2 + 1] << 18) | 
                 ((unsigned int)src[i / 2 + 2] << 11) | ((unsigned int)src[i / 2 + 3] << 4);
        dst[i / 8] = sample;
    }
}
