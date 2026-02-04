#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int n;
extern double res[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n >= 1) {
        res[1] = res[0] / 2.;
    }
    for (m = 2; m <= n; m += 2) {
        res[m] = res[m - 2] / 4.;
        if (m + 1 <= n) {
            res[m + 1] = res[m - 1] / 4.;
        }
    }
}
