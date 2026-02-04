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
    for (x = 0; x < 8; x++) {
        int coeff = (x % 2 == 0) ? (x/2 + 1) : -(x/2 + 1);
        ih += coeff * (top[5 + (x/2)] - top[3 - (x/2)]);
        iv += coeff * (left[5 + (x/2)] - left[3 - (x/2)]);
    }
}
