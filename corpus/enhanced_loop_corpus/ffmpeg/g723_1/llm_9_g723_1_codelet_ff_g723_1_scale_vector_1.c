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
    int shift_factor = bits - 3;
    for (i = 0; i < length; i++) {
        int16_t val = vector[i];
        int32_t product = val << bits;  // Multiply by (1 << bits) using shift
        dst[i] = product >> 3;          // Arithmetic right shift to divide by 8
    }
}
