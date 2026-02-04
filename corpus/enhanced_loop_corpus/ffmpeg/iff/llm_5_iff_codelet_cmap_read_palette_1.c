#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int i;
extern  uint8_t * palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        if (i >= 8 && i < 24) {
            pal[i + 32] = 4278190080U | (((((const uint8_t *)(palette + i * 3))[0] << 16) | (((const uint8_t *)(palette + i * 3))[1] << 8) | ((const uint8_t *)(palette + i * 3))[2]) & 16711422) >> 1;
        } else {
            pal[i + 32] = 4278190080U;
        }
    }
}
