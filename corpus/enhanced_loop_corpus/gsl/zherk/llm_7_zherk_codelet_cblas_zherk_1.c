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
    for (i = 1; i <= N; i++) {
        for (j = 0; j < i; j++) {
            int idx = ldc * (i - 1) + j;
            (((double *)C)[2 * idx]) += 0.;
            (((double *)C)[2 * idx + 1]) += 0.;
        }
    }
}
