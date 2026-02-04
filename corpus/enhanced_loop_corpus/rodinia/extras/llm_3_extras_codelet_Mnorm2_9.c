#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern double *x;
extern int i;
extern double invnorm;
extern double sum;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (iterate from end to beginning)
    int i;
    for (i = len - 1; i >= 0; i--) {
        tmp = x[i] * invnorm;
        sum += tmp * tmp;
    }
}
