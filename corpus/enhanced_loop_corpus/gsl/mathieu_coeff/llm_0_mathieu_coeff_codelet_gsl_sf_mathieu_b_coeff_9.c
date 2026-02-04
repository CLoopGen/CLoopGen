#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int jj = 0; jj < 1; jj++)
        for (ii = 0; ii < 100; ii++)
            coeff[ii] = 0.;
}
