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
    for (pe = npes - 1; pe >= 0; --pe) {
        depend[pe] = sched[pe][step[pe]];
        if (pe > 0) {
            step[pe - 1] = step[pe] + (depend[pe] & 1);
        }
    }
}
