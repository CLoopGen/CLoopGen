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
    // Variant 1: Strided memory access with stride of 2
    done = 1;
    for (int pe = 0; pe < npes; pe += 2) {
        if (pe < npes && sched[pe][step[pe]] != -1) {
            done = 0;
            break;
        }
        int next_pe = pe + 1;
        if (next_pe < npes && sched[next_pe][step[next_pe]] != -1) {
            done = 0;
            break;
        }
    }
}
