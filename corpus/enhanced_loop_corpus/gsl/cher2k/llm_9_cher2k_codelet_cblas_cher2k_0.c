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
    for (j = i; j < N; j += 2) {
        (((float *)C)[2 * (ldc * i + j)]) = 0.;
        (((float *)C)[2 * (ldc * i + j) + 1]) = 0.;
        if (j + 1 < N) {
            (((float *)C)[2 * (ldc * i + j + 1)]) = 0.;
            (((float *)C)[2 * (ldc * i + j + 1) + 1]) = 0.;
        }
    }
}
}
