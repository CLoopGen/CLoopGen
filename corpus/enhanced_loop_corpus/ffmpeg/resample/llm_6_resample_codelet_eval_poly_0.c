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
    double temp_sum = sum;
    for (i = size - 2; i >= 0; --i) {
        temp_sum = temp_sum * x + coeff[i];
    }
    sum = temp_sum;
}
