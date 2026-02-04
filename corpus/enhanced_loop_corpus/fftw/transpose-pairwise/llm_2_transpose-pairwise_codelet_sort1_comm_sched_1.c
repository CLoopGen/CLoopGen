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
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access pattern: sched[i] = sortsched[npes + i] becomes strided on sortsched
    int stride = 2;
    int limit = npes - (npes % stride); // Make sure we don't go out of bounds
    for (i = 0; i < limit; i += stride) {
        sched[i] = sortsched[npes + i];
        if (i + 1 < npes) {
            sched[i + 1] = sortsched[npes + i + 1];
        }
    }
    // Handle remainder if npes is not a multiple of stride
    for (; i < npes; ++i)
        sched[i] = sortsched[npes + i];
}
