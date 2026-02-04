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
        int base_offset_i = 2 * ldc * i;
        for (j = i; j < N; j++) {
            int offset = base_offset_i + 2 * j;
            C_ptr[offset] = 0.;
            C_ptr[offset + 1] = 0.;
        }
    }
}
