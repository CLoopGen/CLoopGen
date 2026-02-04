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
            size_t idx = 2 * (ldc * i + j);
            ((double*)C)[idx] = 0.;
            ((double*)C)[idx + 1] = 0.;
            // Introduce a WAW dependency by writing again to the same location (redundant but valid)
            ((double*)C)[idx] = 0.;
        }
    }
}
