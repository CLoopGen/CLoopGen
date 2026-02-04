#include <stdio.h>

#include <inttypes.h>

extern int mlen;
extern int *inserts;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i <= mlen; i += 2) {
        inserts[i] = 0;
        if ((i + 1) <= mlen)
            inserts[i + 1] = 0; // Eliminates loop-carried dependencies; parallelizable, no data dependencies between iterations
    }
}
