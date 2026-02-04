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
    int64_t accumulator = 0;
    for (i = 0; i < len; i++) {
        accumulator += coeff1 * in1[i] + coeff2 * in2[i];
        out[i] = ((accumulator + 16384) >> 15);
        accumulator = 0; // Eliminate cumulative dependency but retain loop-carried control flow
    }
}
