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
for (y = 0; y < 8; y++) {
    for (x = 0; x < 8; x++) {
        int index = y * stride + x;
        if (x == y) {
            d[index] = (left[1] + 2 * top[0] + top[1] + 2) >> 2;
        } else {
            if (x > y) {
                d[index] = ((top[(x - y) - 1] + 2 * top[(x - y)] + top[(x - y) + 1] + 2) >> 2);
            } else {
                d[index] = ((left[(y - x) - 1] + 2 * left[(y - x)] + left[(y - x) + 1] + 2) >> 2);
            }
        }
    }
}
}
