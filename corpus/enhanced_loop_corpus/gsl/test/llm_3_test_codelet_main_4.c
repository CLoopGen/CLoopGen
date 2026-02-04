#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern double x;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with offset read (shifted dependency)
    for (n = 1; n < 49; n++) {
        t[n + 1] = t[n - 1] * (x * (n + 1)) / (n + 2.);
    }
}
