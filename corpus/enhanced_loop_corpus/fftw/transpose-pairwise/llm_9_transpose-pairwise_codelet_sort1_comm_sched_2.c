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
    for (i = 0; i < npes * 2; i += 2) {
        if (i < npes) {
            sortsched[npes + sortsched[i]] = sched[i];
        }
        if (i + 1 < npes) {
            sortsched[npes + sortsched[i + 1]] = sched[i + 1];
        }
    }
}
