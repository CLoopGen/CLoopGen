#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint8_t *in;
extern uint8_t *out;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < w; j++) {
        int64_t v = (((uint64_t)((const uint8_t *)(in))[0] << 40) | 
                     ((uint64_t)((const uint8_t *)(in))[1] << 32) | 
                     ((uint64_t)((const uint8_t *)(in))[2] << 24) | 
                     ((uint64_t)((const uint8_t *)(in))[3] << 16) | 
                     ((uint64_t)((const uint8_t *)(in))[4] << 8) | 
                     (uint64_t)((const uint8_t *)(in))[5]);

        for (int k = 5; k >= 0; k--) {
            ((uint8_t *)(out))[k] = (v >> (8 * (5 - k)));
        }

        out += 6;
        in -= 6;
    }
}
