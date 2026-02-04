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
        uint16_t temp_left_y = left[y];
        uint16_t temp_left_size = left[size];
        uint16_t temp_top_size = top[size];
        for (x = 0; x < size; x++) {
            uint16_t temp_top_x = top[x];
            int index = x + stride * y;
            int term1 = (size - 1 - x) * temp_left_y;
            int term2 = (x + 1) * temp_top_size;
            int term3 = (size - 1 - y) * temp_top_x;
            int term4 = (y + 1) * temp_left_size;
            int sum = term1 + term2 + term3 + term4 + size;
            src[index] = sum >> (trafo_size + 1);
        }
    }
}
