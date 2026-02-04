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
    for (i = 0; i < npes * 2; i += 2) {
        sched[i/2] = ((void *)0);
        if (i + 1 < npes) {
            sched[(i+1)/2] = ((void *)0);
        }
    }
}
