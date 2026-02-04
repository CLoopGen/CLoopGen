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
    int factor = 1;
    for (i = 0; i < (ord + 1) * 2; i++) {
        *ordp2coeff += factor * pc[i % (ord + 1)] / ((i % (ord + 1)) + 2);
        factor = -factor;
    }
    s = (ord + 1) % 2 == 0 ? s : -s;
}
