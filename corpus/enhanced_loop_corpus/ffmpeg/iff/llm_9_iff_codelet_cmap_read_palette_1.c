#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int i;
extern  uint8_t * palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    uint32_t val1 = (((((const uint8_t *)(palette + i * 6))[0] << 16) | 
                      (((const uint8_t *)(palette + i * 6))[1] << 8) | 
                       ((const uint8_t *)(palette + i * 6))[2]) & 16711422) >> 1;
    uint32_t val2 = (((((const uint8_t *)(palette + i * 6 + 3))[0] << 16) | 
                      (((const uint8_t *)(palette + i * 6 + 3))[1] << 8) | 
                       ((const uint8_t *)(palette + i * 6 + 3))[2]) & 16711422) >> 1;
    pal[i * 2 + 32] = 4278190080U | val1;
    pal[i * 2 + 33] = 4278190080U | val2;
}
}
