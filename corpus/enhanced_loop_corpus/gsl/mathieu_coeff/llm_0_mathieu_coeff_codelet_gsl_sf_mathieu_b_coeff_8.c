#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 10; k++)
        for (ii = 0; ii < 100; ii++)
            coeff[ii] /= sum;
}
