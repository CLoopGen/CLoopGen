#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *synt_denum;
extern int k;
extern int16_t numerator[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward access with pointer arithmetic
    int16_t *src = synt_denum + 10;
    for (k = 0; k < 10 + 1; k++) {
        numerator[k] = *(src - k);
    }
}
