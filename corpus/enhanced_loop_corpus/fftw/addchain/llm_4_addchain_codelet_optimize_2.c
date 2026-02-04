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
for (i = 0; i < n; ++i) {
    for (j = 0; j <= i; ++j) {
        k = i + j;
        if (k < n) {
            int c = A[i] + A[j] + mulcost;
            if (c < A[k]) {
                A[k] = c;
                changed = 1;
            }
        }
        k = i - j;
        if (k >= 0 && k < n) {
            int c = A[i] + A[j] + mulcost;
            if (c < A[k]) {
                A[k] = c;
                changed = 1;
            }
        }
        k = i + j;
        if (i >= j && k < n) {
            int c = A[i] + A[j] + A[i - j] + reflcost;
            if (c < A[k]) {
                A[k] = c;
                changed = 1;
            }
        }
    }
}
}
