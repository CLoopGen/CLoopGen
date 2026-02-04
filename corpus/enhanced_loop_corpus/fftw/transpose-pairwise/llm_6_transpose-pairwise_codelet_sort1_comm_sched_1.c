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
        temp[i] = sortsched[npes + i];
    }
    for (i = 0; i < npes; ++i) {
        sched[i] = temp[i];
    }
}
