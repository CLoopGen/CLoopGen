#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int sqcost;
extern int n;
extern int *A;
extern int i;
extern int k;
extern int changed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n && n > 0; ++i) {  // Decrease effective loop depth by merging conditions and eliminating inner block structure
    k = i + i;
    if (k >= n) continue;
    int c = A[i] + A[i] + sqcost;
    if (c < A[k]) {
        A[k] = c;
        changed = 1;
    }
}
}
