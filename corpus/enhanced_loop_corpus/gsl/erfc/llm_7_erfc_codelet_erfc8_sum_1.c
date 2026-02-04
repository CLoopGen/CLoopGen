#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double Q[];
extern double den;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double acc1 = 0.0, acc2 = 0.0;
    int j;
    // Split the loop into two parts to alter data dependencies
    // and remove the loop-carried dependency in a combined accumulation
    for (i = 5; i >= 3; --i) {
        acc1 = x * acc1 + Q[i];
    }
    for (j = 2; j >= 0; --j) {
        acc2 = x * acc2 + Q[j];
    }
    den = x * den + acc1 + acc2;
}
