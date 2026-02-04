#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int *step;
extern int pe;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = npes * 3;
    for (pe = 0; pe < limit; ++pe) {
        int idx = pe % npes;
        step[idx] = (step[idx] + 1) & 0xFF;
    }
}
