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
    uint32_t base_val = 4278190080U;
    uint32_t r, g, b;
    for (i = 0; i < count; i++) {
        r = ((const uint8_t *)(palette + i * 3))[0];
        g = ((const uint8_t *)(palette + i * 3))[1];
        b = ((const uint8_t *)(palette + i * 3))[2];
        pal[i] = base_val | (r << 16) | (g << 8) | b;
    }
}
