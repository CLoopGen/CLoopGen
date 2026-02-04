#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int next[12];
extern  double shift;
extern int k;
extern double *xdbl;
extern double *ydbl;
extern unsigned int ir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Decreased effective depth by unrolling first iteration and simplifying control flow
int next_k;
k = next[ir];
if (k > 0) {
    ydbl[k] = xdbl[k] + shift;
    next_k = next[k];
    for (; next_k > 0; ) {
        k = next_k;
        ydbl[k] = xdbl[k] + shift;
        next_k = next[k];
    }
}
// Final update of k to maintain original side-effect
k = next_k;
}
