#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int npes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing consecutive rows, we use a stride of 2, wrapping around if necessary.
    int stride = 2;
    int start = 0;
    for (int step = 0; step < npes; ++step) {
        int idx = (start + step * stride) % npes;
        sched[idx][0] = -1;
    }
}
