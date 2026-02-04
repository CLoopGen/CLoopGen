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
    // Variant 1: Consecutive memory access by precomputing left values and using a temporary array
    uint8_t temp[8];
    for (int y = 0; y < 8; y++) {
        temp[y] = ((left[y] + 2 * left[y + 1] + left[y + 2] + 2) >> 2);
    }
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            d[y * stride + x] = temp[y];
        }
    }
}
