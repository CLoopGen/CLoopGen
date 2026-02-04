#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *top;
extern uint8_t *left;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++)
    for (x = 0; x < 4; x++) {
        int offset = y * stride + x;
        if (x == y)
            d[offset] = (left[0] + top[0] + 1) >> 1;
        else if (x > y)
            d[offset] = (top[(x - y)] + 1) >> 1;
        else
            d[offset] = (left[(y - x)] + 1) >> 1;
    }
}
