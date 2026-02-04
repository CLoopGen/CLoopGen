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
    // Variant 2: Reduced trip count with stride-based sampling and simplified logic
    done = 1;
    int stride = (npes > 8) ? npes / 8 : 1;
    for (pe = 0; pe < npes; pe += stride) {
        if (sched[pe][step[pe]] != -1) {
            done = 0;
            break;
        }
    }
}
