#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double Q[];
extern double den;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse access but using pointer arithmetic for memory access modification
    double *q_ptr = Q + 5;
    for (i = 5; i >= 0; --i) {
        den = x * den + *q_ptr;
        q_ptr--;
    }
}
