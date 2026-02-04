#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double w87a[21];
extern double savfun[21];
extern double res87;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp1 = 0.0, temp2 = 0.0;
    for (k = 0; k < 10; k++) {
        temp1 += savfun[k] * w87a[k];
        temp2 += savfun[k + 11] * w87a[k + 11];
    }
    res87 += temp1 + temp2;
}
