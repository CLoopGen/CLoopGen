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
    double temp_res = 0.0;
    for (k = 0; k < 21; k++) {
        temp_res += savfun[k] * w87a[k];
    }
    res87 += temp_res;
}
