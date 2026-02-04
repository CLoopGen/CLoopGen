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
    uint16_t *src_base = &src[stride * y];
    uint16_t left_y = left[y];
    uint16_t left_size = left[size];
    uint16_t top_size = top[size];
    for (x = 0; x < size; x++) {
        src_base[x] = ((size - 1 - x) * left_y + (x + 1) * top_size + (size - 1 - y) * top[x] + (y + 1) * left_size + size) >> (trafo_size + 1);
    }
}
}
