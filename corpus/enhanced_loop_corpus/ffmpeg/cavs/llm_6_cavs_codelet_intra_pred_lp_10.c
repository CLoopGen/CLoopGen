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
    uint8_t temp[8];
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            int top_val = ((top[x] + 2 * top[x + 1] + top[x + 2] + 2) >> 2);
            temp[x] = top_val;
        }
        for (x = 0; x < 8; x++) {
            int left_val = ((left[y] + 2 * left[y + 1] + left[y + 2] + 2) >> 2);
            d[y * stride + x] = (temp[x] + left_val) >> 1;
        }
    }
}
