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
    if (npes > 0) {
        pe = 0;
        for (; pe < npes && sched[pe][step[pe]] == -1; ++pe) {
            // Empty loop body: condition checks exit criteria
        }
        if (pe < npes) {
            done = 0;
        }
    }
}
