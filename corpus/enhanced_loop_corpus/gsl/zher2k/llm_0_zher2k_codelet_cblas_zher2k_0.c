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
        for (int k = 0; k < 1; k++) {
            (((double *)C)[2 * (ldc * i + j)]) = 0.;
            (((double *)C)[2 * (ldc * i + j) + 1]) = 0.;
        }
    }
}
}
