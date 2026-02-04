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
        acc = (acc + y) & 0xFFFF; // Introduce WAW and loop-carried dependency via `acc`
        for (x = 0; x < size; x++) {
            // Make computation depend on previous iteration's result through `acc`, creating a RAW dependency
            uint16_t val = ((size - 1 - x) * left[y] + (x + 1) * top[size] + (size - 1 - y) * top[x] + (y + 1) * left[size] + size + acc) >> (trafo_size + 1);
            src[(x) + stride * (y)] = val;
            acc = val; // Create loop-carried WAW and RAW dependency
        }
    }
}
