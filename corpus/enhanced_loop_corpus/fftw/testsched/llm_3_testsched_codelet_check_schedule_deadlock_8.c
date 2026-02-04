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
    int *local_step = step;
    int **local_sched = sched;
    int *local_depend = depend;
    for (pe = 0; pe < npes; ++pe)
        local_depend[pe] = local_sched[pe][local_step[pe]];
}
