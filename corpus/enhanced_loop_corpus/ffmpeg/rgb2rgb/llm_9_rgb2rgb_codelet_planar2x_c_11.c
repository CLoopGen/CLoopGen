#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < srcWidth - 1; x++) {
        uint16_t a = src[x], b = src[x + 1];
        dst[2 * x + 1] = ((a << 1) + a + b) >> 2;
        dst[2 * x + 2] = (a + (b << 1) + b) >> 2;
    }
}
