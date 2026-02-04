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
    for (y = 0; y < size; y++) {
        int base_y = y * stride;
        uint8_t left_y = left[y];
        uint8_t left_size = left[size];
        for (x = 0; x < size; x++) {
            src[x + base_y] = ((size - 1 - x) * left_y + (x + 1) * top[size] + (size - 1 - y) * top[x] + (y + 1) * left_size + size) >> (trafo_size + 1);
        }
    }
}
