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
    int temp;
    for (pe = 0; pe < npes; ++pe)
        for (i = 0; i < npes / 2; ++i) {
            temp = sched[pe][i];
            sched[pe][i] = sched[pe][npes - 1 - i];
            // Introduce a WAW dependency by writing to the same location twice
            sched[pe][npes - 1 - i] = temp;
            sched[pe][npes - 1 - i] ^= 1; // Additional write to create WAW (loop-independent)
        }
}
