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
        for (i = 1; i < npes / 2; ++i) {
            int prev = sched[pe][i - 1]; // Create RAW dependency on previous iteration
            int curr = sched[pe][i];
            // Modify current based on previous (introduce loop-carried RAW)
            sched[pe][i] = prev;
            sched[pe][i - 1] = curr;
            // Break symmetry: introduce WAR by reordering write-before-read
        }
}
