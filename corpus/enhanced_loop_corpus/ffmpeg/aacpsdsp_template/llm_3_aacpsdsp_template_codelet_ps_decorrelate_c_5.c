#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT g_decay_slope;
extern  INTFLOAT a[];
extern INTFLOAT ag[3];
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive array access using pointer arithmetic
    INTFLOAT *aptr = a;
    INTFLOAT *agptr = ag;
    for (m = 0; m < 3; m++) {
        *(agptr++) = (*(aptr++)) * g_decay_slope;
    }
}
