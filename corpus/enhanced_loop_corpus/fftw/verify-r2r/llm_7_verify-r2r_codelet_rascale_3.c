#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real R;

extern R *a;
extern R alpha;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    R local_alpha = alpha;
    for (i = 0; i < n; ++i) {
        R scratch = a[i] * local_alpha; // Remove write-after-write on a[i] by using local copy
        a[i] = scratch;
    }
    // Eliminate potential loop-carried dependencies by ensuring no state is carried across iterations
    // Each iteration is now fully independent (purely element-wise operation)
}
