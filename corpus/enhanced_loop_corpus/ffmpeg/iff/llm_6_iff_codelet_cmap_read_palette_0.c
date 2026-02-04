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
    uint32_t temp;
    for (i = 0; i < count; i++) {
        temp = ((const uint8_t *)(palette + i * 3))[0];
        temp = (temp << 16) | (((const uint8_t *)(palette + i * 3))[1] << 8);
        temp = (4278190080U | temp) | ((const uint8_t *)(palette + i * 3))[2];
        pal[i] = temp;
    }
}
