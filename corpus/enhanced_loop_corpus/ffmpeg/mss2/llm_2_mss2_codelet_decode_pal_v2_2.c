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
    int j;
    for (j = 0; j < ncol; j++) {
        int idx = 3 * j;
        uint8_t r = ((const uint8_t *)(buf + idx))[0];
        uint8_t g = ((const uint8_t *)(buf + idx))[1];
        uint8_t b = ((const uint8_t *)(buf + idx))[2];
        *pal++ = (r << 16) | (g << 8) | b;
    }
}
