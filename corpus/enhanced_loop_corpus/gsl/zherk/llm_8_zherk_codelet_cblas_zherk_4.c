#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            (((double *)C)[2 * (ldc * i + i) + 1]) = 0.;
            (((double *)C)[2 * (ldc * (i + 1) + (i + 1)) + 1]) = 0.;
        } else {
            (((double *)C)[2 * (ldc * i + i) + 1]) = 0.;
        }
    }
}
