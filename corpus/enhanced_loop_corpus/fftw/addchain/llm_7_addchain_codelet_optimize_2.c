#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mulcost;
extern int reflcost;
extern int n;
extern int *A;
extern int i;
extern int j;
extern int k;
extern int changed;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < n; ++i) {  // Start from 1 to allow safe use of i-1
    for (j = 0; j < n; ++j) {  // Remove loop-carried dependency on i by decoupling j's bound
        k = j;
        if (i + 1 < n) {
            int c = A[i] + A[i+1] + mulcost;  // Introduce RAW dependency on future element
            if (c < A[k]) {
                A[k] = c;
                changed = 1;
            }
        }
        if (i - 1 >= 0) {
            int c = A[i] + A[i-1] + mulcost;  // Create WAW hazard on A[k] with prior write
            if (c < A[k]) {
                A[k] = c;
                changed = 1;
            }
        }
        if (j > 0) {
            int c = A[j] + A[j-1] + reflcost;  // Add WAR-like pattern via backward access
            if (c < A[i]) {
                A[i] = c;  // WAW on A[i] across iterations
                changed = 1;
            }
        }
    }
}
}
