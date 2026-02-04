#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *A;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; ++i) {
        ((A[i])[1]) = ((A[i-1])[1]);
    }
    if (n > 0) {
        ((A[0])[1]) = 0.;
    }
    // Introduces a loop-carried WAW and WAR dependency
    // Each iteration writes A[i][1] based on prior iteration's value (RAW dependency)
    // Replaces unconditional zeroing with a shift-like behavior, last value propagated forward
    // Final result: all elements become 0 only if initial A[0][1] is set to 0 at end
    // Mutation changes data flow but maintains memory access safety
}
