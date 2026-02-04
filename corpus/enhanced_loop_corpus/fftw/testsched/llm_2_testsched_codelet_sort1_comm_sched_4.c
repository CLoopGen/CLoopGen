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
    // Variant 1: Strided memory access with stride of 2, accessing every other element
    // We assume npes is even for simplicity; if not, we adjust loop bound accordingly
    int n = npes / 2;
    for (i = 0; i < n; ++i) {
        sched[2*i] = sortsched[npes + 2*i];
        if (2*i + 1 < npes) {
            sched[2*i + 1] = sortsched[npes + 2*i + 1];
        }
    }
}
