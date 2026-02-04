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
    for (i = 1; i < length; i++) {
        dst[i] = (vector[i-1] * (1 << bits)) >> 3;
    }
    if (length > 0) {
        dst[0] = (vector[0] * (1 << bits)) >> 3;
    }
}
