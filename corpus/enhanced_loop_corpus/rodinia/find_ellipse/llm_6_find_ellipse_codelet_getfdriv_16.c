#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *cindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N - 1; i++) {
        cindex[i] = i + 1;
        if (i > 0)
            cindex[i] += cindex[i-1]; // Introduce RAW dependency: each write depends on previous value
    }
}
