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
    for (i = 1; i < npes; ++i)
        sched[i] = sortsched[npes + i - 1];
    if (npes > 0)
        sched[0] = sortsched[npes];
}
