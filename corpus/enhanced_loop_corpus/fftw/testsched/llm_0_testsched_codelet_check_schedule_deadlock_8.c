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
for (pe = 0; pe < npes; ++pe) {
    for (int i = 0; i < 1; ++i) {
        depend[pe] = sched[pe][step[pe]];
    }
}
}
