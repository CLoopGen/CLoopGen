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
for (y = 0; y < 8; y += 2)
    for (x = 0; x < 8; x += 2) {
        int top_val = ((top[x] + 2 * top[x+1] + top[x+2] + 2) >> 2);
        int left_val = ((left[y] + 2 * left[y+1] + left[y+2] + 2) >> 2);
        d[y * stride + x] = (top_val + left_val) >> 1;
        if (x + 1 < 8) d[y * stride + x + 1] = top_val;
        if (y + 1 < 8) d[(y + 1) * stride + x] = left_val;
    }
}
