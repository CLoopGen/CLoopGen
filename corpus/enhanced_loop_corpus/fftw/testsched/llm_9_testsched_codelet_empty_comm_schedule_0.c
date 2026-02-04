#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int npes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < npes; i += step) {
        if (i + 1 < npes) {
            sched[i][0] = -1;
            sched[i + 1][0] = -1;
        } else {
            sched[i][0] = -1;
        }
    }
}
