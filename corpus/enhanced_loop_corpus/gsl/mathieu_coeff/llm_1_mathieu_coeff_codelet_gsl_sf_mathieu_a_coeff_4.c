#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double coeff[];
extern int ii;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 10; ii++) {
        for (int kk = 0; kk < 10; kk++) {
            int idx = ii * 10 + kk;
            coeff[idx] /= sum;
        }
    }
}
