#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int n;
extern double res[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (m = 1; m <= n; m++) {
        if (res[m - 1] > 0.0) {
            res[m] = res[m - 1] / 2.;
        } else {
            res[m] = 0.0;
        }
    }
}
