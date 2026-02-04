#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double t[50];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with offset base (skip first few, then process consecutively)
    int start = 5;
    for (n = start; n < 45; n++) {
        t[n] = -t[n - 1] * (4. * (n + 1.) - 1.) / (3.1415926535897931 * 3.1415926535897931);
    }
}
