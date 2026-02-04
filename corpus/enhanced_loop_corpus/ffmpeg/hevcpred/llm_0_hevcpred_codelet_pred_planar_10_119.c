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
for (y = 0; y < size; y++) {
    for (x = 0; x < size; x++) {
        for (ptrdiff_t s = 0; s < 1; s++) {
            src[(x) + stride * (y)] = ((size - 1 - x) * left[y] + (x + 1) * top[size] + (size - 1 - y) * top[x] + (y + 1) * left[size] + size) >> (trafo_size + 1);
        }
    }
}
}
