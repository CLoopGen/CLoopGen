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
    int y_cond = (y < size / 2);
    for (x = 0; x < size; x++) {
        int x_cond = (x >= size / 2);
        if (y_cond && !x_cond) {
            src[x + stride * y] = ((size - 1 - x) * left[y] + (x + 1) * top[size] + 
                                   (size - 1 - y) * top[x] + (y + 1) * left[size] + size) >> (trafo_size + 1);
        } else if (!y_cond && x_cond) {
            src[x + stride * y] = ((x + 1) * top[size] + (size - 1 - x) * left[y] + 
                                   (y + 1) * left[size] + (size - 1 - y) * top[x] + size) >> (trafo_size + 1);
        } else {
            src[x + stride * y] = (top[x] + left[y] + size) >> (trafo_size + 1);
        }
    }
}
}
