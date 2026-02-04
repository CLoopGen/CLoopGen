#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int npes;
extern int *step;
extern int *depend;
extern int pe;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[npes];
    for (pe = 0; pe < npes; ++pe) {
        temp[pe] = sched[pe][step[pe]];
    }
    for (pe = 0; pe < npes; ++pe) {
        depend[pe] = temp[pe];
    }
}
