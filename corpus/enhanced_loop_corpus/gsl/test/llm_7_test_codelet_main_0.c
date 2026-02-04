#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double f[100];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 100; i += 2) { // Unroll-like effect with stride 2, removing WAW dependencies by writing non-overlapping indices
        f[i] = 0;
        if (i + 1 < 100)
            f[i + 1] = 0;
    }
}
