#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int npes;
extern int pe;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pe = 0; pe < npes; ++pe)
        for (i = 0; i < npes / 2; ++i) {
            int idx1 = i;
            int idx2 = npes - 1 - i;
            int temp = sched[pe][idx1];
            sched[pe][idx1] = sched[pe][idx2];
            sched[pe][idx2] = temp;
        }
}
