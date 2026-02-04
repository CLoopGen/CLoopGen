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
    for (i = 0; i < npes; ++i) {
        int temp1 = sortsched[i];
        int temp2 = npes + temp1;
        sortsched[temp2] = sched[i];
        sortsched[i] = temp1 + 1; // Additional write to increase computation
    }
}
