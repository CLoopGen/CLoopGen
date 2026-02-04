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
    // Variant 1: Consecutive (forward) memory access by reordering computation
    // We reverse the iteration order and adjust indexing to write consecutively into sortsched
    for (i = npes - 1; i >= 0; --i)
        sortsched[2 * npes - 1 - i] = sched[npes - 1 - i];
}
