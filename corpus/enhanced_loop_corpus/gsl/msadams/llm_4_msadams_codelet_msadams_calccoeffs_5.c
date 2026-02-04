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
    for (i = 0; i < ord + 1; i++) {
        if (i % 2 == 0) {
            *ordp2coeff += s * pc[i] / (i + 2);
        } else {
            *ordp2coeff -= s * pc[i] / (i + 2);
        }
        s = -s;
    }
}
