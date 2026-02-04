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
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled inner loop by factor of 2
    // Trip count remains the same but operations per iteration are increased, simulating higher computational load
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x += 2) {
            // First element of unrolled pair
            if (x < size) {
                int idx1 = x + stride * y;
                int temp1 = (size - 1 - x) * left[y] + (x + 1) * top[size] + (size - 1 - y) * top[x] + (y + 1) * left[size];
                int offset1 = (temp1 + size + (temp1 >> (trafo_size))) >> (trafo_size + 1);
                src[idx1] = (uint8_t)(offset1 & 0xFF);
            }
            // Second element of unrolled pair
            if (x + 1 < size) {
                int idx2 = (x + 1) + stride * y;
                int temp2 = (size - 1 - (x + 1)) * left[y] + ((x + 1) + 1) * top[size] + (size - 1 - y) * top[x + 1] + (y + 1) * left[size];
                int offset2 = (temp2 + size + (temp2 >> (trafo_size))) >> (trafo_size + 1);
                src[idx2] = (uint8_t)(offset2 & 0xFF);
            }
        }
    }
}
