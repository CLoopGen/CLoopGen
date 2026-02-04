#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int npes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[npes];
    for (i = 0; i < npes; ++i) {
        temp[i] = -1;
    }
    for (i = 0; i < npes; ++i) {
        sched[i][0] = temp[i];
    }
}
