#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double r;
extern double rk;
extern double sum;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 3; k < 8; k++) {
    double ds1, ds2;
    rk *= r;
    ds1 = rk / (k * k * (k + 1.));
    ds2 = (rk * r) / ((k+1) * (k+1) * (k + 2.)); // Extra term with lookahead effect
    sum += ds1 + ds2;
}
}
