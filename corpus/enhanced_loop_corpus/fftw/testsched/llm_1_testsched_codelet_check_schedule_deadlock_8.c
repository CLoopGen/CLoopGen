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
if (npes > 0) {
    pe = 0;
    for (; pe < npes; ++pe)
        depend[pe] = sched[pe][step[pe]];
}
}
