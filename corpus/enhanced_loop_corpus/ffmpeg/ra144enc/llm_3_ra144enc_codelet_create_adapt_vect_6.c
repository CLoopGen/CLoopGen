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
    // Variant 2: Reverse consecutive memory access (traverse from high to low index)
    int bound = (40 > lag) ? lag : 40;
    for (i = bound - 1; i >= 0; i--) {
        vect[i] = cb[i];
    }
}
