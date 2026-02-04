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
    int j;
    for (i = 0; i < npes * 2; i += 2) {
        int idx1 = sortsched[i % npes];
        int offset1 = npes + idx1;
        sortsched[offset1] = sched[i % npes];

        if (i + 1 < npes * 2) {
            int idx2 = sortsched[(i + 1) % npes];
            int offset2 = npes + idx2;
            sortsched[offset2] = sched[(i + 1) % npes];
        }
    }
}
