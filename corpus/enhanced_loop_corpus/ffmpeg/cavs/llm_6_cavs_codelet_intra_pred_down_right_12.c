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
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            if (x == y)
                temp[y * 8 + x] = (left[1] + 2 * top[0] + top[1] + 2) >> 2;
            else if (x > y)
                temp[y * 8 + x] = ((top[(x - y) - 1] + 2 * top[(x - y)] + top[(x - y) + 1] + 2) >> 2);
            else
                temp[y * 8 + x] = ((left[(y - x) - 1] + 2 * left[(y - x)] + left[(y - x) + 1] + 2) >> 2);
        }
    }
    for (int i = 0; i < 64; i++) {
        d[i / 8 * stride + i % 8] = temp[i];
    }
}
