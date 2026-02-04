#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *left;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; ++y) {
    uint8_t base_val = left[y + 1];
    uint8_t sum = base_val + base_val;
    for (x = 0; x < 8; x++) {
        if (x & 1) {
            d[y * stride + x] = (sum + left[y] + left[y + 2] + 2) >> 2;
        } else {
            d[y * stride + x] = (sum + left[y] + base_val + 2) >> 2;
        }
    }
}
}
