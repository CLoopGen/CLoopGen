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
for (k = 2; k < 10; k++) {
    double ds;
    rk *= r;
    if (k % 2 == 0) {
        ds = rk / (k * k * (k + 1.));
        sum += ds;
    }
}
}
