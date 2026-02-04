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
    double ds[10];
    for (k = 2; k < 10; k++) {
        rk *= r;
        ds[k] = rk / (k * k * (k + 1.));
    }
    for (k = 2; k < 10; k++) {
        sum += ds[k];
    }
}
