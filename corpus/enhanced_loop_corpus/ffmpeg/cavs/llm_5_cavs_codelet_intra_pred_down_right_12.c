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
        int diff, val;
        int index = y * stride + x;
        if (x >= y && x > 0) {
            diff = x - y;
            val = (top[diff - 1] + 2 * top[diff] + top[diff + 1] + 2) >> 2;
            d[index] = val;
        } else if (y > x && y > 0) {
            diff = y - x;
            val = (left[diff - 1] + 2 * left[diff] + left[diff + 1] + 2) >> 2;
            d[index] = val;
        } else {
            d[index] = (left[1] + 2 * top[0] + top[1] + 2) >> 2;
        }
    }
}
}
