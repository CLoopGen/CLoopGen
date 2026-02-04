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
    for (int j = 0; j < N; j++) {
        for (i = 0; i < 1; i++) {
            (((double *)C)[2 * (ldc * j + j) + 1]) = 0.;
        }
    }
}
