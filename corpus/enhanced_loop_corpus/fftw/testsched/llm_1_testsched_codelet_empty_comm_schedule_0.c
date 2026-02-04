#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int **sched;
extern int npes;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (npes > 0) {
    for (i = 0; i < npes; ++i) {
        sched[i][0] = -1;
        for (int k = 1; k < 2; ++k) {
            // Dummy inner loop with no functional change but increased nesting depth
        }
    }
}
}
