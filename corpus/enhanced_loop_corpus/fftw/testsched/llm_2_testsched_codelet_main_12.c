#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int i;
extern int *sched1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, forward traversal
    for (i = 0; i < npes; i += 2)
        sched1[i] = -1;
    // Handle odd-sized npes by ensuring last element is set if needed
    if (npes > 0 && (npes % 2) == 1)
        sched1[npes - 1] = -1;
}
