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
    for (i = 0; i < npes; ++i) {
        int index = 2 * npes - 1 - sortsched[i];
        if (index >= 0)
            sortsched[index] = sched[i];
        else
            sortsched[0] = 0;
    }
}
