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
            int idx = x + y + 2;
            uint8_t top_val = ((top[idx - 1] + 2 * top[idx] + top[idx + 1] + 2) >> 2);
            uint8_t left_val = ((left[idx - 1] + 2 * left[idx] + left[idx + 1] + 2) >> 2);
            d[y * stride + x] = (top_val + left_val) >> 1;
        }
    }
}
