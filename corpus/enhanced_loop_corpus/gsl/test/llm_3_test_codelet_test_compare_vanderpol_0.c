#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[11][2];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = ns; i-- > 0; ) {
        y[i][0] = 1.;
        y[i][1] = 0.;
    }
}
