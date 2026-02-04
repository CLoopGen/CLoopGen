#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int n;
extern double res[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = 1; m <= n; m += 2) {
    if (m <= n) {
        res[m] = res[m - 1] / 2.0;
    }
    if (m + 1 <= n) {
        res[m + 1] = (res[m] / 2.0) + (res[m - 1] / 4.0);
    }
}
}
