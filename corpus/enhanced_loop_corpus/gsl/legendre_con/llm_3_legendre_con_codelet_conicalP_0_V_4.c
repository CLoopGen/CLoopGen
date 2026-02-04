#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double t;
extern  double f;
extern double T[8];
extern double H[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access – process array from high to low index
    for (i = 7; i >= 1; i--) {
        T[i] = T[i - 1] * t;
        H[i] = H[i - 1] * (t * f);
    }
}
