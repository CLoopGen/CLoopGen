#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern double block1[64];
extern double s;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; ++i) {
        int even_row = 2 * i;
        int odd_row = even_row + 1;
        for (j = 0; j < 8; ++j) {
            int col_offset = j;
            int even_idx = 8 * even_row + col_offset;
            int odd_idx = 8 * odd_row + col_offset;

            double b_even = block[even_idx];
            double b_odd = block[odd_idx];
            double sum = b_even + b_odd;
            double diff = b_even - b_odd;

            if (sum >= 0) {
                block1[even_idx] = sum * s;
            } else {
                block1[even_idx] = -sum * s;
            }

            if (diff < 0) {
                block1[odd_idx] = -diff * s;
            } else {
                block1[odd_idx] = diff * s;
            }
        }
    }
}
