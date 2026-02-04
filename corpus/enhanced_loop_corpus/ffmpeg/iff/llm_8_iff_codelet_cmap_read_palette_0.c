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
    for (i = 0; i < count; i += 2) {
        pal[i] = 4278190080U | ((((const uint8_t *)(palette + i * 3))[0] << 16) | (((const uint8_t *)(palette + i * 3))[1] << 8) | ((const uint8_t *)(palette + i * 3))[2]);
        if (i + 1 < count) {
            pal[i + 1] = 4278190080U | ((((const uint8_t *)(palette + (i + 1) * 3))[0] << 16) | (((const uint8_t *)(palette + (i + 1) * 3))[1] << 8) | ((const uint8_t *)(palette + (i + 1) * 3))[2]);
        }
    }
}
