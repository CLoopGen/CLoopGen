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
        for (i = 0; i < npes / 4; ++i) {
            int dummy = sched[pe][2 * i];
            sched[pe][2 * i] = sched[pe][npes - 1 - 2 * i];
            sched[pe][npes - 1 - 2 * i] = dummy;
        }
}
