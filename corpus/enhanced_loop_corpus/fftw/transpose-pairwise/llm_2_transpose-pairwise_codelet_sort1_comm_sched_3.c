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
    // Variant 1: Consecutive memory access by reversing the iteration order and adjusting indices
    // This changes the access pattern on sortsched to be more sequential in output
    for (i = npes - 1; i >= 0; --i)
        sortsched[i] = sched[2 * npes - 1 - i];
}
