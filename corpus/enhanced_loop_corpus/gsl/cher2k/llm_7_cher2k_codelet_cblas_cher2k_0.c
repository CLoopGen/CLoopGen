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
    float *C_ptr = (float *)C;
    int stride = 2 * ldc;
    for (i = 0; i < N; i++) {
        int base_idx = 2 * ldc * i;
        for (j = i; j < N; j++) {
            int idx = base_idx + 2 * j;
            C_ptr[idx] = 0.;
            C_ptr[idx + 1] = 0.;
        }
    }
}
