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
    for (i = 1; i < n; ++i) {
        k = i - 1;
        int c = A[k] + A[i] + sqcost;
        if (c < A[i]) {
            A[i] = c;
            changed = 1;
        }
    }
}
