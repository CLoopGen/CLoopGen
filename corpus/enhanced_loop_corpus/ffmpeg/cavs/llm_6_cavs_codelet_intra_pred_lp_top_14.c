#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *top;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[8];
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            temp[x] = ((top[(x + 1) - 1] + 2 * top[(x + 1)] + top[(x + 1) + 1] + 2) >> 2);
        }
        for (x = 0; x < 8; x++) {
            d[y * stride + x] = temp[x];
        }
    }
}
