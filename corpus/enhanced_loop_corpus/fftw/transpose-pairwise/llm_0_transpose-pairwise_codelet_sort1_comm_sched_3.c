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
    for (int j = 0; j < npes; ++j)
        for (i = 0; i < 1; ++i)
            sortsched[2 * npes - 1 - sortsched[j]] = sched[j];
}
