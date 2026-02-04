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
for (i = 0; i < npes - 1; ++i)
    for (j = i + 1; j < npes; ++j)
        if (sched[sort_pe][i] > sched[sort_pe][j]) {
            int *temp_row = (int*)malloc(npes * sizeof(int));
            for (pe = 0; pe < npes; ++pe) {
                temp_row[pe] = sched[pe][i];
            }
            for (pe = 0; pe < npes; ++pe) {
                sched[pe][i] = sched[pe][j];
            }
            for (pe = 0; pe < npes; ++pe) {
                sched[pe][j] = temp_row[pe];
            }
            free(temp_row);
        }
}
