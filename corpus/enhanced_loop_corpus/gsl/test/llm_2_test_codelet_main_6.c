#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (step of 2), forward traversal
    for (n = 0; n < 50; n += 2) {
        t[n] = (n == 0) ? 1.23 : 0.;
    }
    // Fill in the odd indices in a second pass to maintain full array coverage
    for (n = 1; n < 50; n += 2) {
        t[n] = 0.;
    }
}
