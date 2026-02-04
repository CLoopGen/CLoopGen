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
    int *indices = (int*)malloc((ni + 1) / 2 * sizeof(int));
    if (!indices) return; // Handle allocation failure
    for (int temp_i = 0; temp_i < (ni + 1) / 2; ++temp_i) {
        indices[temp_i] = temp_i * 2; // Even indices only
    }
    for (i = 0; i < (ni + 1) / 2; ++i) {
        sump += p[indices[i]];
        sumq += q[indices[i]] - 1;
    }
    free(indices);
}
