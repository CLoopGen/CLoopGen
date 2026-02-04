#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int n;
extern double res[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 1; i <= n; i++) {
    for (m = i; m <= i; m++) {
        res[m] = res[m - 1] / 2.;
    }
}
}
