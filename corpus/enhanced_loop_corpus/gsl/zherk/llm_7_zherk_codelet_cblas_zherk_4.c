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
    double *C_ptr = (double *)C;
    double temp = 0.0;
    for (i = 0; i < N; i++) {
        int index = 2 * (ldc * i + i) + 1;
        temp = temp + 1.0; // Eliminate loop-carried dependency on memory, use local accumulation
        C_ptr[index] = temp;
    }
}
