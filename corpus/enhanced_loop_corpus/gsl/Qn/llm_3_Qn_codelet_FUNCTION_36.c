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
    // Variant 2: Indirect memory access using an index array (simulated with stride-like pattern via pointer arithmetic)
    int *index = (int*)malloc(ni * sizeof(int));
    if (!index) exit(1);
    for (int j = 0; j < ni; ++j) {
        index[j] = j; // Simulate arbitrary reorderable indices
    }
    for (i = 0; i < ni; ++i) {
        int idx = index[i]; // Use indirect addressing
        sump += p[idx];
        sumq += q[idx] - 1;
    }
    free(index);
}
