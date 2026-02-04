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
for (y = 0; y < size; y += 2) {
    for (x = 0; x < size; x += 2) {
        int y_end = (y + 1 < size) ? y + 2 : y + 1;
        int x_end = (x + 1 < size) ? x + 2 : x + 1;
        for (int y_inner = y; y_inner < y_end; y_inner++) {
            for (int x_inner = x; x_inner < x_end; x_inner++) {
                src[(x_inner) + stride * (y_inner)] = ((size - 1 - x_inner) * left[y_inner] + (x_inner + 1) * top[size] + (size - 1 - y_inner) * top[x_inner] + (y_inner + 1) * left[size] + size) >> (trafo_size + 1);
            }
        }
    }
}
}
