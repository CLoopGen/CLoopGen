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
    uint16_t acc = 0;
    for (y = 0; y < size; y++) {
        acc = (y == 0) ? 0 : acc + left[y-1]; // Introduce loop-carried dependency (WAW and RAW)
        for (x = 0; x < size; x++) {
            uint16_t val = ((size - 1 - x) * (left[y] + acc) + (x + 1) * top[size] + 
                            (size - 1 - y) * top[x] + (y + 1) * left[size] + size + acc) >> (trafo_size + 1);
            src[(x) + stride * (y)] = val;
        }
    }
}
