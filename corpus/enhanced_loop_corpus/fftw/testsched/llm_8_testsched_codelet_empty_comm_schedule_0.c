#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int npes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < npes; ++i) {
        sched[i][0] = -1;
        sched[i][1] = -2;
        sched[i][2] = -3;
    }
}
