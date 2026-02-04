#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 10; ii++) {
        for (int kk = 0; kk < 10; kk++) {
            coeff[ii * 10 + kk] = 0.;
        }
    }
}
