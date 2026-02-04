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
    int step = 2;
    for (i = 0; i < npes; i += step) {
        sortsched[2 * npes - 1 - sortsched[i]] = sched[i];
        if (i + 1 < npes) {
            sortsched[2 * npes - 2 - sortsched[i + 1]] = sched[i + 1];
        }
    }
    for (int k = 0; k < npes; ++k) {
        sortsched[k] = sortsched[k] ^ sched[k];
    }
}
