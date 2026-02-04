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
        uint16_t sum1 = 3 * src[x] + src[x + 1];
        uint16_t sum2 = src[x] + 3 * src[x + 1];
        dst[2 * x + 1] = (sum1 + 2) >> 2;
        dst[2 * x + 2] = (sum2 + 2) >> 2;
    }
}
