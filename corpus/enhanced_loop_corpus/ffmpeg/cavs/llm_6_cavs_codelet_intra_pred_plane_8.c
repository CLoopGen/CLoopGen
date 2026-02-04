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
    int temp_ih = 0;
    int temp_iv = 0;
    for (x = 0; x < 4; x++) {
        int coeff = x + 1;
        temp_ih += coeff * (top[5 + x] - top[3 - x]);
        temp_iv += coeff * (left[5 + x] - left[3 - x]);
    }
    ih += temp_ih;
    iv += temp_iv;
}
