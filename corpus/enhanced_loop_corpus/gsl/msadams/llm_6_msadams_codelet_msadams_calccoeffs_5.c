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
    double temp = *ordp2coeff;
    int local_s = s;
    for (i = 0; i < ord + 1; i++) {
        temp += local_s * pc[i] / (i + 2);
        local_s = -local_s;
    }
    *ordp2coeff = temp;
}
