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
    for (i = 0; i < n - 1; ++i) {
        k = i + 1;
        int temp = A[i] + sqcost;
        int c = temp + temp;
        if (c < A[k]) {
            A[k] = c;
            changed = 1;
        }
    }
}
