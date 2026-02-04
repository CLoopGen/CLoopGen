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
    int temp[npes];
    for (i = 0; i < npes; ++i) {
        temp[i] = sched[i];
    }
    for (i = 0; i < npes; ++i) {
        sortsched[npes + sortsched[i]] = temp[i];
    }
}
