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
            int temp1 = sched[pe][i] + sched[pe][npes - 1 - i];
            int temp2 = sched[pe][i] - sched[pe][npes - 1 - i];
            sched[pe][i] = temp1 ^ temp2;
            sched[pe][npes - 1 - i] = temp1 & temp2;
        }
}
