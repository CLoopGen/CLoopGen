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
    if (npes <= 0) return;
    for (i = 0; i < npes; ++i) {
        sched[i] = sortsched[npes + i];
    }
}
