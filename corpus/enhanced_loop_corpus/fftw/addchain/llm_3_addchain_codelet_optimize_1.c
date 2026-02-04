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
for (i = 2; i < n; i += 2) {
    k = i;
    if (k < n) {
        int c = A[i - 1] + A[i - 1] + sqcost;
        if (c < A[k]) {
            A[k] = c;
            changed = 1;
        }
    }
    ;
}
}
