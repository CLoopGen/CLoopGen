#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int npes;
extern int *step;
extern int pe;
extern int done;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    done = 1;
    for (pe = 0; pe < npes; ++pe) {
        int temp = sched[pe][step[pe]];
        if (temp != -1) {
            done = 0;
        }
    }
}
