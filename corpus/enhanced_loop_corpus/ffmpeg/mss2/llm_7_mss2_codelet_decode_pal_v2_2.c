#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int i;
extern int ncol;
extern uint32_t *pal;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ncol; i++) {
        uint8_t b0 = ((const uint8_t *)(buf + 3 * i))[0];
        uint8_t b1 = ((const uint8_t *)(buf + 3 * i))[1];
        uint8_t b2 = ((const uint8_t *)(buf + 3 * i))[2];
        *pal++ = (b0 << 16) | (b1 << 8) | b2;
    }
}
