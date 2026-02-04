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
    float *C_ptr = (float *)C;
    int stride = ldc + 1;
    for (i = 0; i < N; i++) {
        int index = 2 * (stride * i) + 1;
        C_ptr[index] = 0.;
    }
}
