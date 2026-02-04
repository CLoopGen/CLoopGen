#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x_out;
extern  int x_out_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x_out = 0; x_out < x_out_max; ++x_out) {
        const int I = x_out * 2;
        const int J = I + 1;
        const int v = J > 0 ? J * x_out : 0;
        // Introduces RAW dependencies: x_out -> I, I -> J, J and x_out -> v
        // Loop-carried dependency via x_out is preserved but no cross-iteration data dependence
    }
}
