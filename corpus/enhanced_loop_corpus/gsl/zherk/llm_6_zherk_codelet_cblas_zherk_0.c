#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            int index = 2 * (ldc * i + j);
            ((double *)C)[index] = 0.;
            ((double *)C)[index + 1] = 0.;
            // Introduce artificial RAW dependency: current iteration depends on previous j value
            if (j > i) {
                ((double *)C)[index] += ((double *)C)[index - 2]; // Read after write from same i, previous j
            }
        }
    }
}
