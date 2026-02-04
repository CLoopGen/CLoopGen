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
    for (i = 0; i < ord + 1; i += 2) {
        if (i + 1 <= ord) {
            *ordp2coeff += s * pc[i] / (i + 2);
            *ordp2coeff += (-s) * pc[i + 1] / (i + 3);
        } else {
            *ordp2coeff += s * pc[i] / (i + 2);
        }
        s = -s;
    }
}
