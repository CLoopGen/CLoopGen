#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[20];
extern double sum;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_t = 0.0;
    sum = 0.0;
    for (n = 0; n < 20; n++) {
        double np1 = n + 1.;
        t[n] = 1. / (np1 * np1);
        sum += t[n] + prev_t; // Introduce loop-carried dependency: each iteration depends on prior t[n-1] via prev_t (RAW)
        prev_t = t[n]; // Create dependency on previous iteration's t value
    }
}
