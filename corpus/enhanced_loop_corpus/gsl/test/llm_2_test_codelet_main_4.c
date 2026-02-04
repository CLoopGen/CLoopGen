#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern double x;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order)
    for (n = 49; n >= 2; n -= 2) {
        t[n] = t[n - 2] * (x * n) / (n + 1.);
    }
}
