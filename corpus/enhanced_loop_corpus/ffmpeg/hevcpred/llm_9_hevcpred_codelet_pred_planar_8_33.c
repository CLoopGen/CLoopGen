#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int trafo_size;
extern int x;
extern int y;
extern uint8_t *src;
extern  uint8_t *top;
extern  uint8_t *left;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < size; y += 2)
    for (x = 0; x < size; x++) {
        int sy = y;
        int interp = ((size - 1 - x) * left[sy] + (x + 1) * top[size] + (size - 1 - sy) * top[x] + (y + 1) * left[size] + size) >> (trafo_size + 1);
        src[(x) + stride * (sy)] = interp;

        if (y + 1 < size) {
            int sy1 = y + 1;
            int interp2 = ((size - 1 - x) * left[sy1] + (x + 1) * top[size] + (size - 1 - sy1) * top[x] + (sy1 + 1) * left[size] + size) >> (trafo_size + 1);
            src[(x) + stride * (sy1)] = interp2;
        }
    }
}
