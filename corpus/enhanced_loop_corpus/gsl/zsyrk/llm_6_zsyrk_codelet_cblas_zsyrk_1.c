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
    for (j = 0; j <= i; j++) {
        int index = 2 * (ldc * i + j);
        ((double *)C)[index] = 0.;
        ((double *)C)[index + 1] = 0.;
        // Introduce artificial RAW dependency: each iteration depends on previous j's computation
        if (j > 0) {
            ((double *)C)[index] += ((double *)C)[index - 2]; // Flow dependency on prior j
        }
    }
}
}
