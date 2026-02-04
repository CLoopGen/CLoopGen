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
    int base_idx = ldc * i;
    for (j = 0; j <= i; j++) {
        int idx = 2 * (base_idx + j);
        float *C_ptr = (float *)C;
        C_ptr[idx] = 0.;
        C_ptr[idx + 1] = 0.;
    }
}
}
