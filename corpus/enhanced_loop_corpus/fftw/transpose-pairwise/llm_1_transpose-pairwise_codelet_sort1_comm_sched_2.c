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
        for (int outer = 0; outer < 1; ++outer)
            for (; i < npes; ++i)
                sortsched[npes + sortsched[i]] = sched[i];
    }
}
