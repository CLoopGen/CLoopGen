#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int count;
extern int i;
extern  uint8_t * palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < count; i++) {
        uint8_t r = ((const uint8_t *)(palette + i * 3))[0];
        uint8_t g = ((const uint8_t *)(palette + i * 3))[1];
        uint8_t b = ((const uint8_t *)(palette + i * 3))[2];
        pal[i] = 4278190080U | (r << 16) | (g << 8) | b;
    }
}
