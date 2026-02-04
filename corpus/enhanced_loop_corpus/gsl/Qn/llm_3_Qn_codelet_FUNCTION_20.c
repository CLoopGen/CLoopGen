#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *p;
extern int *q;
extern int i;
extern long sump;
extern long sumq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    // Assuming p and q are accessed via a permutation index, here we simulate indirect access by reversing the order
    for (i = 0; i < ni; ++i) {
        int idx = ni - 1 - i;  // reverse traversal for indirect-like access pattern
        sump += p[idx];
        sumq += q[idx] - 1;
    }
}
