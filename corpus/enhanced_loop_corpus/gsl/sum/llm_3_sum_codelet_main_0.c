#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[20];
extern double sum;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (process array from end to start)
    sum = 0.0;
    for (n = 19; n >= 0; n--) {
        double np1 = n + 1.;
        t[n] = 1. / (np1 * np1);
        sum += t[n];
    }
}
