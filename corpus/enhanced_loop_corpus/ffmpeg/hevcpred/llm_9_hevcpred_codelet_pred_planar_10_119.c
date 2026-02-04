#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int trafo_size;
extern int x;
extern int y;
extern uint16_t *src;
extern  uint16_t *top;
extern  uint16_t *left;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified expression and increased effective trip count via unrolling simulation
    int double_size = size << 1;
    for (y = 0; y < size; y++) {
        for (x = 0; x < double_size; x += 2) {
            int ux = x >> 1; // equivalent to x / 2
            uint16_t interpolated = (top[ux] + left[y] + size) >> trafo_size;
            src[ux + stride * y] = interpolated;
            if (ux + 1 < size) {
                src[(ux + 1) + stride * y] = interpolated ^ ((left[size] + top[size]) >> trafo_size);
            }
        }
    }
}
