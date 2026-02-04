#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int n;
extern double res[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from high to low
    for (m = n; m >= 1; m--) {
        res[m] = res[m - 1] / 2.;
    }
}
