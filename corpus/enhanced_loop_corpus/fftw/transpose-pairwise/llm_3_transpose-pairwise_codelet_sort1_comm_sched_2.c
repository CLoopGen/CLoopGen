#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sched;
extern int npes;
extern int *sortsched;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (coalesced) write access with indirect read
    // Reorder reads via an index permutation for indirect access, but write consecutively
    int *temp = (int*)malloc(npes * sizeof(int));
    if (!temp) return; // Handle allocation failure

    // Indirect read: gather values using shuffled indices
    for (i = 0; i < npes; ++i) {
        int shuffled_idx = (sortsched[i] + i) % npes; // Create indirect access pattern
        temp[i] = sched[shuffled_idx];
    }

    // Consecutive write: store results in contiguous locations starting at npes
    for (i = 0; i < npes; ++i) {
        sortsched[npes + i] = temp[i];
    }

    free(temp);
}
