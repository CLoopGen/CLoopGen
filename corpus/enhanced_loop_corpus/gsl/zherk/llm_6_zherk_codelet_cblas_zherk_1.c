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
    int k;
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j++) {
            k = 2 * (ldc * i + j);
            (((double *)C)[k]) = 0.;
            (((double *)C)[k + 1]) = 0.;
        }
    }
}
