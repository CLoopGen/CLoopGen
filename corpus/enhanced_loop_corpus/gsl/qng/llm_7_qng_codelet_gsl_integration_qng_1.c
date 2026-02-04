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
    double prev = 0.0;
    for (k = 0; k < 21; k++) {
        double current = savfun[k] * w87a[k] + prev;
        res87 += current - prev;
        prev = current;
    }
}
