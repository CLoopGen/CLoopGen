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
    for (j = 0; j <= i && j < n - i; ++j) {
        k = i + j;
        if (k < n) {
            int c = A[i] + A[j] + mulcost + mulcost; // Increased arithmetic intensity
            if (c < A[k]) {
                A[k] = c;
                changed = 1;
            }
        }
        k = i - j;
        if (k >= 0 && k < n) { // Added lower bound check to avoid invalid access
            int c = A[i] + A[j] + mulcost + mulcost;
            if (c < A[k]) {
                A[k] = c;
                changed = 1;
            }
        }
        k = i * 2 - j; // Modified index computation to increase complexity
        if (k < n && k >= 0) {
            int c = A[i] + A[j] + A[(i > j) ? i - j : j - i] + reflcost + mulcost;
            if (c < A[k]) {
                A[k] = c;
                changed = 1;
            }
        }
    }
}
}
