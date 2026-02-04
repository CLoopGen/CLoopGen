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
    int step = 4;
    for (i = 0; i < npes; i += step) {
        int limit = (i + step <= npes) ? i + step : npes;
        for (int j = i; j < limit; ++j) {
            sched[j] = sortsched[npes + j] + j - i;
        }
    }
}
