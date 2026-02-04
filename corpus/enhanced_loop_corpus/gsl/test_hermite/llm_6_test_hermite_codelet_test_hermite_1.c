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
        res[m] = res[m - 1] / 2.0;
        res[m] += res[0] / (m + 1); // Introduce additional read dependency on res[0], creating a new non-loop-carried dependency
    }
}
