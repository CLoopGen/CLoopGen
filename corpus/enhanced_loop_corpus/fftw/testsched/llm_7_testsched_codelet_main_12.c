#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int i;
extern int *sched1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < npes; ++i) {
        if (i > 0)
            sched1[i] = sched1[i-1]; // Introduce RAW dependency: current depends on previous
        else
            sched1[i] = -1;
    }
}
