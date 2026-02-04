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
    // Variant 2: Strided output write - instead of writing full rows, write column-wise with stride in d
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            int val = ((left[(y + 1) - 1] + 2 * left[(y + 1)] + left[(y + 1) + 1] + 2) >> 2);
            d[y * stride + x] = val;
        }
    }
}
