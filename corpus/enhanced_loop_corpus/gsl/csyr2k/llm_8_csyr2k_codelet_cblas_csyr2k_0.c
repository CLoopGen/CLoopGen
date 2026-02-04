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
        int index = 2 * (ldc * i + j);
        float *c_ptr = (float *)C;
        c_ptr[index] = 0.;
        c_ptr[index + 1] = 0.;
        c_ptr[index + 2] = 0.;
        c_ptr[index + 3] = 0.;
    }
}
}
