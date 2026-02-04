#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[2][3];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2 in a padded logical array
    // Simulate a strided access pattern by treating the 2x3 array as having a larger row stride
    // Here, we only write to even indices (i += 2), creating a strided access pattern across rows
    for (i = 0; i < ns; i += 2) {
        y[i][0] = 1.;
        y[i][1] = 2.;
        y[i][2] = 3.;
    }
    // Handle remaining odd index if ns is odd
    if (ns > 0 && (ns - 1) % 2 == 1) {
        y[ns - 1][0] = 1.;
        y[ns - 1][1] = 2.;
        y[ns - 1][2] = 3.;
    }
}
