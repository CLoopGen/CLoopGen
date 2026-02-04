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
    // Variant 1: Strided memory access pattern
    // Instead of accessing sortsched[i] consecutively, use a stride of 2 (with modulo to stay in bounds)
    // This creates a non-consecutive access pattern in the source index
    for (i = 0; i < npes; ++i) {
        int src_index = (i * 2) % npes;  // Strided access to sched and base index in sortsched
        sortsched[npes + sortsched[src_index]] = sched[src_index];
    }
}
