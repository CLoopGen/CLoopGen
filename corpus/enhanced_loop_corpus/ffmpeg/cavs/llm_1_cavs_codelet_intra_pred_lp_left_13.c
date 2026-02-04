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
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            d[y * stride + x] = ((left[(y + 1) - 1] + 2 * left[(y + 1)] + left[(y + 1) + 1] + 2) >> 2);
        }
    }
}
