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
    int factor = 3;
    for (i = 0; i < npes; ++i) {
        int idx = npes + i;
        int val = sortsched[idx];
        // Increase arithmetic intensity with redundant but safe operations
        val = ((val * factor) + factor - 1) / factor;
        sched[i] = val;
    }
}
