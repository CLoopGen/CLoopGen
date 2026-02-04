#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *a;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; ++i) {
        ((a[i])[0]) = ((a[i])[0]) * 2.0;
        ((a[i])[0]) = 0.;
    }
    // Introduces WAW (write-after-write) and WAR (write-after-read) dependencies
    // WAW: two writes to the same location a[i][0]
    // WAR: reading a[i][0] after it has been written in the same iteration (via multiplication)
    // Eliminates any potential use of prior values beyond the current iteration — no loop-carried dependency
    // Semantically reduces to simple assignment to 0, but with artificial intra-iteration dependencies
}
