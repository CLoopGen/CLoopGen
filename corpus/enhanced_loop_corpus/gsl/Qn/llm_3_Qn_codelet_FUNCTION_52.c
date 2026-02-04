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
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    int *index = (int*)malloc(ni * sizeof(int));
    if (!index) return; // Handle allocation failure
    for (int j = 0; j < ni; ++j) {
        index[j] = j; // Identity mapping for indirect access
    }
    for (i = 0; i < ni; ++i) {
        int idx = index[i]; // Simulate indirect access
        sump += p[idx];
        sumq += q[idx] - 1;
    }
    free(index);
}
