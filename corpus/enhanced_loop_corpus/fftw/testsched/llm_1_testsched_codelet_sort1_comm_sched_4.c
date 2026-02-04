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
if (npes > 0) {
    i = 0;
    for (int temp = 0; temp < npes; ++temp) {
        sched[i] = sortsched[npes + i];
        ++i;
    }
}
}
