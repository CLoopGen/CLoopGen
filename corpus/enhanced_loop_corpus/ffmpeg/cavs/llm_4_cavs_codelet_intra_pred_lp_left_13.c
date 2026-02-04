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
for (y = 0; y < 8; y++) {
    uint8_t temp1, temp2, temp3;
    for (x = 0; x < 8; x++) {
        temp1 = left[y];
        temp2 = left[y + 1];
        temp3 = left[y + 2];
        if (x >= 4) {
            d[y * stride + x] = ((temp1 + 2 * temp2 + temp3 + 2) >> 2);
        } else {
            d[y * stride + x] = ((temp2 + 2 * temp1 + temp2 + 2) >> 2);
        }
    }
}
}
