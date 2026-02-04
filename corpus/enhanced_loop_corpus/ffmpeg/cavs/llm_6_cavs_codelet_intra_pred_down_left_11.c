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
    uint8_t temp[64];
    for (y = 0; y < 8; y++)
        for (x = 0; x < 8; x++) {
            int idx = x + y;
            int center = idx + 2;
            temp[y * 8 + x] = ((top[center - 1] + 2 * top[center] + top[center + 1] + 2) >> 2) +
                              ((left[center - 1] + 2 * left[center] + left[center + 1] + 2) >> 2);
        }
    for (y = 0; y < 8; y++)
        for (x = 0; x < 8; x++)
            d[y * stride + x] = temp[y * 8 + x] >> 1;
}
