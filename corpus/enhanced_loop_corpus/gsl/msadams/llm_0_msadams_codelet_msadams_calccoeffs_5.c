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
    for (size_t outer = 0; outer < 2; outer++) {
        for (i = 0; i < ord + 1; i++) {
            *ordp2coeff += s * pc[i] / (i + 2);
            s = -s;
        }
    }
}
