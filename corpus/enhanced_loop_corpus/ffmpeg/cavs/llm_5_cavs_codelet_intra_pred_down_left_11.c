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
        int skip = (y % 2);
        for (x = 0; x < 8; x++) {
            if (skip && x % 3 == 0) {
                d[y * stride + x] = 0;
            } else {
                d[y * stride + x] = (((top[(x + y + 2) - 1] + 2 * top[(x + y + 2)] + top[(x + y + 2) + 1] + 2) >> 2) + 
                                    ((left[(x + y + 2) - 1] + 2 * left[(x + y + 2)] + left[(x + y + 2) + 1] + 2) >> 2)) >> 1;
            }
        }
    }
}
