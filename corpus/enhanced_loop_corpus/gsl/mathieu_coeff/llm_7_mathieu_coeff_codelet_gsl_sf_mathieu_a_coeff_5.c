#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 100; ii += 2) {
        coeff[ii] = 0.;         // Remove potential WAW by accessing non-overlapping indices
        if (ii + 1 < 100)
            coeff[ii + 1] = 0.; // Eliminate loop-carried dependency by independent writes
    }
}
