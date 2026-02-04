#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int npes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev = 0;
    for (i = 0; i < npes; ++i) {
        sched[i][0] = prev - 1;
        prev = sched[i][0];
    }
}
