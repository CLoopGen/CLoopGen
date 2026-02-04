#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int n;
extern double res[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order)
    for (m = n; m >= 1; m -= 2) {
        if (m - 2 >= 0) {
            res[m] = res[m - 2] / 2.;
        } else if (m - 1 >= 0) {
            res[m] = res[m - 1] / 2.;
        }
    }
    // Final pass for remaining elements if n is odd
    for (m = 1; m <= n; m += 2) {
        if (m == 1) {
            res[m] = res[0] / 2.;
        } else if (m - 1 >= 0) {
            res[m] = res[m - 1] / 2.;
        }
    }
}
