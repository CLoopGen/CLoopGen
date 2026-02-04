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
    // Variant 1: Strided memory access (forward traversal with stride of 2)
    // We convert the original linked-list-like traversal into a regular strided array access.
    // Assume that 'next' array was previously encoding a linked structure; now we simplify to stride.
    int i;
    for (i = ir; i < 12; i += 2) {
        if (next[i] > 0 && next[i] < 12) {
            ydbl[next[i]] = xdbl[next[i]] + shift;
        }
    }
}
