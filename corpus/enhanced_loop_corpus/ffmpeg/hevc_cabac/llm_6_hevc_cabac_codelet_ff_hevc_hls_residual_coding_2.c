#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *c = coeffs;
    for (i = 0; i < 8; i++) {
        int16_t temp1 = c[i];
        int16_t temp2 = c[15 - i];
        c[i] = temp2;
        c[15 - i] = temp1;
    }
}
