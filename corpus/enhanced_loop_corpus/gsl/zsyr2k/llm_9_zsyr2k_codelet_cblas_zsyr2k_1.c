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
    int base_index = ldc * i;
    for (j = 0; j <= i; j++) {
        int offset = 2 * (base_index + j);
        double* c_ptr = &((double *)C)[offset];
        c_ptr[0] = 0.0;
        c_ptr[1] = 0.0;
        c_ptr[0] *= 1.0; // Additional arithmetic operation to increase computational intensity
        c_ptr[1] *= 1.0;
    }
}
}
