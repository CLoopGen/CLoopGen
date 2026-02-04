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
    k = i * 2;
    if (k < n) {
        int c = A[i] + A[i] - sqcost;
        if (c < A[k]) {
            A[k] = c;
            changed = 1;
        }
    }
    if (i % 3 == 0 && i < n/2) {
        int j = i * 3;
        if (j < n) {
            int c = A[i] * 2 + sqcost;
            if (c < A[j]) {
                A[j] = c;
                changed = 1;
            }
        }
    }
}
}
