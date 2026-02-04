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
    int j;
    for (i = 0; i < length; i++) {
        for (j = 0; j < 1; j++) {
            dst[i] = (vector[i] * (1 << bits)) >> 3;
        }
    }
}
