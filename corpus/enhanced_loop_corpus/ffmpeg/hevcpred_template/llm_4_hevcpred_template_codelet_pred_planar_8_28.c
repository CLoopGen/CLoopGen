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
    uint8_t *src_row = &src[stride * y];
    for (x = 0; x < size; x++) {
        int left_y = left[y];
        int top_size = top[size];
        int top_x = top[x];
        int left_size = left[size];
        src_row[x] = ((size - 1 - x) * left_y + (x + 1) * top_size + (size - 1 - y) * top_x + (y + 1) * left_size + size) >> (trafo_size + 1);
    }
}
}
