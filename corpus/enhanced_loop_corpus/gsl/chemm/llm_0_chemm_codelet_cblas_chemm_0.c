#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *C;
extern  int ldc;
extern int i;
extern int j;
extern int n1;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j += 2) {
        int index_base = ldc * i + j;
        if (j + 1 < n2) {
            // Unroll two iterations: process j and j+1
            (((float *)C)[2 * index_base]) = 0.;
            (((float *)C)[2 * index_base + 1]) = 0.;
            (((float *)C)[2 * (index_base + 1)]) = 0.;
            (((float *)C)[2 * (index_base + 1) + 1]) = 0.;
        } else {
            // Handle last element if n2 is odd
            (((float *)C)[2 * index_base]) = 0.;
            (((float *)C)[2 * index_base + 1]) = 0.;
        }
    }
}
}
