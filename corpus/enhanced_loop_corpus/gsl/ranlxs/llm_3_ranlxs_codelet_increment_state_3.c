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
    // Variant 2: Consecutive memory access with offset indexing
    // Instead of following an indirect index chain via 'next[]', traverse a contiguous block.
    // Simulate batch processing on a segment starting from 'next[ir]' and process N elements consecutively.
    int start = next[ir];
    int n = (start > 6) ? 6 : start;  // Limit number of iterations for safety
    int i;
    for (i = 0; i < n; i++) {
        int idx = start - i;  // Reverse consecutive access
        ydbl[idx] = xdbl[idx] + shift;
    }
}
