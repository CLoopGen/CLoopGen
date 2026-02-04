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
        int base_i = ldc * i;
        float* C_ptr = (float*)C;
        for (j = i; j < N; j++) {
            int index = 2 * (base_i + j);
            C_ptr[index] = 0.;
            C_ptr[index + 1] = 0.;
        }
        if (i < N - 1) {
            int next_index = 2 * (ldc * (i+1) + (i+1));
            ((float*)C)[next_index] = ((float*)C)[2*(ldc*i + N-1)]; 
        }
    }
}
