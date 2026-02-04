#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int i;
extern  uint8_t * palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp;
    for (i = 0; i < 32; i++) {
        temp = ((const uint8_t *)(palette + i * 3))[0] << 16;
        temp |= ((const uint8_t *)(palette + i * 3))[1] << 8;
        temp |= ((const uint8_t *)(palette + i * 3))[2];
        temp = (temp & 16711422) >> 1;
        pal[i + 32] = 4278190080U | temp;
    }
}
