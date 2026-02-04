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
for (y = 0; y < 16; y++)
    for (x = 0; x < 16; x++) {
        int idx = y * stride + x;
        if ((x == y) && (x % 2 == 0))
            d[idx] = (left[1] + 3 * top[0] + 2 * top[1] + left[0] + 4) >> 3;
        else if (x > y)
            d[idx] = ((top[(x - y) - 1] + 2 * top[(x - y)] + top[(x - y) + 1] + 2) >> 2);
        else
            d[idx] = ((left[(y - x) - 1] + 2 * left[(y - x)] + left[(y - x) + 1] + 2) >> 2);
    }
}
