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
    ptrdiff_t idx;
    uint16_t accum = 0;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            idx = (x) + stride * (y);
            accum += ((size - 1 - x) * left[y] + (x + 1) * top[size] + (size - 1 - y) * top[x] + (y + 1) * left[size] + size) >> (trafo_size + 1);
            src[idx] = accum;
        }
    }
}
