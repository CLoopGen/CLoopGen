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
    for (i = 0; i < N; i++) {
        int index = ldc * i + i;
        double *ptr = (double *)C;
        ptr[2 * index] = 1.0;
        ptr[2 * index + 1] = 0.0;
        ptr[2 * index + 2] = -1.0;
    }
}
