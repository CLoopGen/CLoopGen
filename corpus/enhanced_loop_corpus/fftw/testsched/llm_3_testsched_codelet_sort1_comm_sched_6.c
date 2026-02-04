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
    // Variant 2: Strided memory access on both arrays
    // Introduce a stride of 2, accessing every second element to create strided pattern
    // Adjust loop bound to avoid out-of-bounds access
    int stride = 2;
    int effective_npes = (npes + stride - 1) / stride; // ceiling division
    for (i = 0; i < effective_npes; ++i) {
        int idx = i * stride;
        if (idx < npes) {
            sortsched[2 * npes - 1 - sortsched[idx]] = sched[idx];
        }
    }
}
