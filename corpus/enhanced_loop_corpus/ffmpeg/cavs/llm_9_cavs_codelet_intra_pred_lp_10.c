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
        int avg_top = (top[x] + top[x+1] + 2) >> 2;
        int avg_left = (left[y] + left[y+1] + 2) >> 2;
        int result = (avg_top + avg_left) >> 1;
        d[(2*y) * stride + (2*x)] = result;
        d[(2*y) * stride + (2*x)+1] = result;
        d[(2*y)+1 * stride + (2*x)] = result;
        d[(2*y)+1 * stride + (2*x)+1] = result;
    }
}
