#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    for (x = 0; x < 8; x++) {
        int sum = 0;
        for (int offset = 0; offset < 4; offset++) {
            sum += src[(8 + 8 + 1) + x + offset * 16];
        }
        dst[x] = (sum + 2) >> 2; // Average of 4 values
    }
    dst += stride;
}
}
