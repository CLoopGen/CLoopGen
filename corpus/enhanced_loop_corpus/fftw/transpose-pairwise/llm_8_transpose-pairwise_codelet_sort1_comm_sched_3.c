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
    int j;
    for (i = 0; i < npes * 2; ++i) {
        if (i < npes) {
            sortsched[2 * npes - 1 - sortsched[i]] = sched[i];
        } else {
            j = i - npes;
            sortsched[j] += sortsched[j] ^ sched[j % npes];
        }
    }
}
