#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern int n;
extern double res[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write with offset read (shifted access pattern using temporary indexing)
    int base = 0;
    for (m = 1; m <= n; m++) {
        int idx = base + m;
        res[idx] = res[idx - 1] / 2.;
    }
}
