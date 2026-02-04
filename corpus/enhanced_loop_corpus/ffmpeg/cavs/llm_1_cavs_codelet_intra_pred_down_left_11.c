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
    for (y = 0; y < 64; y++) {
        x = y & 7;
        int row = y >> 3;
        int idx = x + row + 2;
        d[row * stride + x] = (((top[idx - 1] + 2 * top[idx] + top[idx + 1] + 2) >> 2) + ((left[idx - 1] + 2 * left[idx] + left[idx + 1] + 2) >> 2)) >> 1;
    }
}
