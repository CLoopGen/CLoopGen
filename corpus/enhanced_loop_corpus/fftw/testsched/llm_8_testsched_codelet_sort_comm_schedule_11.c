#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int npes;
extern int sort_pe;
extern int i;
extern int j;
extern int pe;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < npes; ++i)
    for (j = i + 1; j < npes; ++j)
        if (sched[sort_pe][i] > sched[sort_pe][j]) {
            for (pe = 0; pe < npes; ++pe) {
                int s = sched[pe][i];
                sched[pe][i] = sched[pe][j];
                sched[pe][j] = s;
            }
        }
}
