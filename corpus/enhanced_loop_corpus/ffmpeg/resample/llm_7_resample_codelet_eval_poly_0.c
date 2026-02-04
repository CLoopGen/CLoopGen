#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *coeff;
extern int size;
extern double x;
extern double sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_coeff_prev = (size > 1) ? coeff[size - 2] : 0.0;
    for (i = size - 2; i >= 0; --i) {
        sum += local_coeff_prev;
        sum *= x;
        local_coeff_prev = (i > 0) ? coeff[i - 1] : 0.0;
    }
    if (size <= 1) sum += 0;
}
