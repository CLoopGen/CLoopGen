#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern double x;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev = t[0];
    for (n = 1; n < 50; n++) {
        double next_val = prev * (x * n) / (n + 1.);
        t[n] = next_val;
        prev = next_val;
    }
}
