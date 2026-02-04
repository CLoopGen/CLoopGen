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
    int *index = (int*)malloc(ni * sizeof(int));
    if (!index) return; // Handle allocation failure
    for (i = 0; i < ni; ++i) {
        index[i] = i; // Assume indirect indexing pattern, e.g., could be shuffled or non-linear in real use
    }
    for (i = 0; i < ni; ++i) {
        sump += p[index[i]];
        sumq += q[index[i]] - 1;
    }
    free(index);
}
