#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *dindex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N - 2; i++) {
        dindex[i] = i + 2;
        dindex[i + 1] = dindex[i] + 1; // Introduces RAW dependency: read after write on dindex[i]
    }
}
