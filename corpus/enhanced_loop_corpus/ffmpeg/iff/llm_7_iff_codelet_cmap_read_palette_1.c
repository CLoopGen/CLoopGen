#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int i;
extern  uint8_t * palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t prev = 0;
    for (i = 0; i < 32; i++) {
        uint32_t component = 4278190080U | (((((const uint8_t *)(palette + i * 3))[0] << 16) | 
                                           (((const uint8_t *)(palette + i * 3))[1] << 8) | 
                                           ((const uint8_t *)(palette + i * 3))[2]) & 16711422) >> 1;
        pal[i + 32] = component ^ prev;
        prev = component;
    }
}
