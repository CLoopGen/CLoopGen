#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sched;
extern int npes;
extern int *sortsched;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (npes > 0) {
        i = 0;
        for (int outer = 0; outer < npes; ++outer)
            for (int inner = 0; inner < 1; ++inner)
                if (outer == i) {
                    sortsched[2 * npes - 1 - sortsched[i]] = sched[i];
                    ++i;
                }
    }
}
