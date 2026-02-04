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
    // Variant 1: Strided memory access (access every second element, starting from i=5 and stepping by -2)
    for (i = 5; i >= 0; i -= 2) {
        den = x * den + Q[i];
        if (i > 0) {
            den = x * den + Q[i-1];  // Emulate unrolled effect with strided pattern
        }
    }
}
