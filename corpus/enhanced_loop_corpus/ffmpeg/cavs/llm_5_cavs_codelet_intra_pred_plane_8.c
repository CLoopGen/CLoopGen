#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *top;
extern uint8_t *left;
extern int x;
extern int ih;
extern int iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 4; ++x) {
        int coeff = x + 1;
        int top_diff = top[5 + x] - top[3 - x];
        int left_diff = left[5 + x] - left[3 - x];
        
        if (top_diff > 0) {
            ih += coeff * top_diff;
        }
        if (left_diff != 0) {
            iv += coeff * left_diff;
        }
    }
}
