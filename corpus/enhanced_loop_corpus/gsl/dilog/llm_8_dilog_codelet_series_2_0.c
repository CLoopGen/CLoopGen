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
for (k = 2; k < 15; k += 2) {
    double ds;
    rk *= r * r;
    ds = rk / (k * k * (k + 1.) * (k + 2.));
    sum += ds;
    sum -= rk / (k * (k + 3.)); // Additional computation to increase intensity
}
}
