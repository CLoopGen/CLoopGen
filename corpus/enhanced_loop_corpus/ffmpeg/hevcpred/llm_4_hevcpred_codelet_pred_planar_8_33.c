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
        uint8_t *src_base = &src[stride * y];
        uint8_t left_y = left[y];
        uint8_t top_size = top[size];
        uint8_t left_size = left[size];
        int size_m1 = size - 1;
        for (x = 0; x < size; x++) {
            uint8_t top_x = top[x];
            int term1 = (size_m1 - x) * left_y;
            int term2 = (x + 1) * top_size;
            int term3 = (size_m1 - y) * top_x;
            int term4 = (y + 1) * left_size;
            src_base[x] = (term1 + term2 + term3 + term4 + size) >> (trafo_size + 1);
        }
    }
}
