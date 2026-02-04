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
        int temp = sortsched[i];
        if (temp < npes) {
            sortsched[npes + temp] = sched[i];
        } else {
            sortsched[temp - npes] = sched[i];
        }
    }
}
