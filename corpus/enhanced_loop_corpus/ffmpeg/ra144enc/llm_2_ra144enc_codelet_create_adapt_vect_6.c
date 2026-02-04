#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *vect;
extern  int16_t *cb;
extern int lag;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    int bound = (40 > lag) ? lag : 40;
    for (i = 0; i < bound; i += 2) {
        vect[i] = cb[i];
    }
    // Handle remaining element if bound is odd
    if (bound % 2 == 1 && i == bound - 1) {
        vect[i] = cb[i];
    }
}
