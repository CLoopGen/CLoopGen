#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern  int16_t *vector;
extern int length;
extern int bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < length; i++) {
        int shift_amount = bits - 3;
        if (shift_amount > 0) {
            dst[i] = vector[i] << shift_amount;
        } else {
            dst[i] = vector[i] >> (3 - bits);
        }
    }
}
