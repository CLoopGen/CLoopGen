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
    uint8_t local_left = left[size];
    for (y = 0; y < size; y++) {
        uint8_t base_val = (local_left + size) >> (trafo_size + 1);
        for (x = 0; x < size; x++) {
            uint8_t contrib = ((size - 1 - x) * left[y] + (x + 1) * top[size] + (size - 1 - y) * top[x] + (y + 1) * local_left);
            src[(x) + stride * (y)] = base_val + (contrib >> (trafo_size + 1));
        }
    }
}
