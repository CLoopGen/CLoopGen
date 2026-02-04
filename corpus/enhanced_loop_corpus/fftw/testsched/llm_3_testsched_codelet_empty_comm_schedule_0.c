#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int npes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping
    // Create a local index permutation to access sched in non-consecutive, indirect order.
    int *indices = (int*)malloc(npes * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Create reverse order mapping for indirect access
    for (int j = 0; j < npes; ++j) {
        indices[j] = npes - 1 - j;
    }

    for (int j = 0; j < npes; ++j) {
        int idx = indices[j];
        sched[idx][0] = -1;
    }

    free(indices);
}
