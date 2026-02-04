#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int32_t *out;
extern  int32_t *in1;
extern  int32_t *in2;
extern integer len;
extern int i;
extern int64_t coeff1;
extern int64_t coeff2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < len; j++) {
        int temp = 0;
        for (int k = 0; k < 1; k++) { // Artificially nested with fixed inner iteration
            temp = ((coeff1 * in1[j] + coeff2 * in2[j]) + 16384) >> 15;
        }
        out[j] = temp;
    }
}
