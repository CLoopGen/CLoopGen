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
for (y = 0; y < size; y++)
    for (x = 0; x < size; x += 2) {
        int val1 = ((size - 1 - x) * left[y] + (x + 1) * top[size] + (size - 1 - y) * top[x] + (y + 1) * left[size] + size) >> (trafo_size + 1);
        int val2 = (x + 1 < size) ? 
            ((size - 1 - (x+1)) * left[y] + (x + 2) * top[size] + (size - 1 - y) * top[x+1] + (y + 1) * left[size] + size) >> (trafo_size + 1) : val1;
        src[(x) + stride * (y)] = val1;
        if (x + 1 < size) src[(x+1) + stride * (y)] = val2;
    }
}
