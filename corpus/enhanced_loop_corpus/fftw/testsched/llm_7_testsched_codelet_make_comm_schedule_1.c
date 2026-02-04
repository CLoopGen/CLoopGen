#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int **sched;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (npes > 0) {
        sched[0] = ((void *)0);
        for (i = 1; i < npes; ++i)
            sched[i] = sched[i-1]; // Introduces loop-carried WAR dependency: each write depends on prior iteration's write
    }
}
