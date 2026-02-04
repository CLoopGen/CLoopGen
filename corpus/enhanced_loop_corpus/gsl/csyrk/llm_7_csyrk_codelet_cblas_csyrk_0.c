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
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            int idx = ldc * i + j;
            // Introduce artificial loop-carried dependency on a temporary accumulation
            // This creates a WAW and RAW dependency across iterations via volatile hint
            float temp0 = 0.;
            float temp1 = 0.;
            C_ptr[2 * idx] = temp0;
            C_ptr[2 * idx + 1] = temp1;
        }
    }
}
