#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[20];
extern double sum;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in two passes)
    sum = 0.0;
    for (n = 0; n < 20; n += 2) {
        double np1 = n + 1.;
        t[n] = 1. / (np1 * np1);
        sum += t[n];
    }
    for (n = 1; n < 20; n += 2) {
        double np1 = n + 1.;
        t[n] = 1. / (np1 * np1);
        sum += t[n];
    }
}
