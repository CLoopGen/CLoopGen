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
    for (i = 0; i < npes - 1; ++i) {
        int min_idx = i;
        for (j = i + 1; j < npes; ++j) {
            if (sched[sort_pe][j] < sched[sort_pe][min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            for (pe = 0; pe < npes; ++pe) {
                int s = sched[pe][i];
                sched[pe][i] = sched[pe][min_idx];
                sched[pe][min_idx] = s;
            }
        }
    }
}
