#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x_lp;
extern int len;
extern float x_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed loop order (backward traversal)
    for (int j = (len >> 2) - 1; j >= 0; j--) {
        x_lp4[j] = x_lp[2 * j];
    }
}
