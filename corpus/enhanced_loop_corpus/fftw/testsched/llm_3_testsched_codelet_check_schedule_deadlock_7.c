#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int *step;
extern int pe;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated with stride reversal)
    int *index_map = (int*)malloc(npes * sizeof(int));
    if (!index_map) return; // Early return on allocation failure

    // Create a reverse index mapping: access elements in reverse order
    for (int i = 0; i < npes; ++i)
        index_map[i] = npes - 1 - i;

    // Use indirect addressing via the index map
    for (int pe = 0; pe < npes; ++pe)
        step[index_map[pe]] = 0;

    free(index_map);
}
