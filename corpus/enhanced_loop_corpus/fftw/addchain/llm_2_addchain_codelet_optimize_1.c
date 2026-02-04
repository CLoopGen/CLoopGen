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
for (i = 0; i < n; ++i) {
    k = i + i;
    if (k < n) {
        int c = A[i] + A[i] + sqcost;
        if (c < A[k + 1]) {
            A[k + 1] = c;
            changed = 1;
        }
    }
    ;
}
}
