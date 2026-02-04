#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 63; i++) {
        uint16_t coeff1 = 64 - (i + 1);
        uint16_t coeff2 = i + 1;
        if ((coeff1 & 1) == 0) {
            filtered_top[i] = (coeff1 * top[-1] + coeff2 * top[63] + 32) >> 6;
        } else {
            filtered_top[i] = (coeff2 * top[63] + coeff1 * top[-1] + 32) >> 6;
        }
    }
}
