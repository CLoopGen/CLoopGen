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
    // Variant 2: Indirect memory access using an index map (simulated via reversed order)
    // This changes access pattern to reverse traversal of the source array
    for (i = 0; i < npes; ++i) {
        int idx = npes - 1 - i;  // reverse index mapping
        sched[i] = sortsched[npes + idx];
    }
}
