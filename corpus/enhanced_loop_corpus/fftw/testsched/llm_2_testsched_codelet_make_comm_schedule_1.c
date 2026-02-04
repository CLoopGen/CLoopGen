#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int **sched;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < npes; j += 2) {
        if (j + 1 < npes) {
            sched[j] = ((void *)0);
            sched[j + 1] = ((void *)0);
        } else {
            sched[j] = ((void *)0);
        }
    }
}
