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
    int stride = (npes > 8) ? 4 : 1;
    for (i = 0; i < npes; i += stride) {
        int temp1 = sortsched[i];
        int temp2 = sched[i];
        int index = 2 * npes - 1 - temp1;
        sortsched[index] = temp2 ^ temp1;
    }
}
