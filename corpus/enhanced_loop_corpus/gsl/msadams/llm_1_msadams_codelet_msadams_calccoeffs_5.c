#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ord;
extern double pc[];
extern double *ordp2coeff;
extern size_t i;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (ord + 1 > 0) {
        i = 0;
        for (size_t step = 0; step < (ord + 1 + 1) / 2; step++) {
            *ordp2coeff += s * pc[i] / (i + 2);
            s = -s;
            i++;
            if (i < ord + 1) {
                *ordp2coeff += s * pc[i] / (i + 2);
                s = -s;
                i++;
            }
        }
    }
}
