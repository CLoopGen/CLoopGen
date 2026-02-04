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
        int index = sortsched[i];
        if (index < npes && index >= 0) {
            sortsched[npes + index] = sched[i];
        } else {
            sortsched[i] = -1;
        }
    }
}
