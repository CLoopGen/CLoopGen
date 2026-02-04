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
for (i = 0; i < n; i += 2) {
    k = i + i;
    if (k + 1 < n) {
        int c1 = A[i] + A[i] + sqcost;
        int c2 = A[i + 1] + A[i + 1] + sqcost;
        if (c1 < A[k]) {
            A[k] = c1;
            changed = 1;
        }
        if (c2 < A[k + 1]) {
            A[k + 1] = c2;
            changed = 1;
        }
    }
}
}
