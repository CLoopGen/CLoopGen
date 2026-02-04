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
    for (i = npes - 1; i >= 0; --i) {
        int index = sortsched[i];
        sortsched[npes + index] = sched[i];
        sortsched[i] = index; // Write back to create WAW dependency with potential future iterations
    }
}
