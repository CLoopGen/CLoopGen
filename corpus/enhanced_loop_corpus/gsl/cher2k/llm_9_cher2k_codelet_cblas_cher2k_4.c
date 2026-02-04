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
    int prev_index = -1;
    for (i = 0; i < N; i++) {
        int curr_offset = 2 * (ldc * i + i) + 1;
        if (prev_index != -1) {
            C_ptr[prev_index] = C_ptr[curr_offset] + C_ptr[prev_index];
        }
        C_ptr[curr_offset] = 0.;
        prev_index = curr_offset;
    }
    if (N > 0) {
        int last_index = 2 * (ldc * (N-1) + (N-1)) + 1;
        C_ptr[last_index] = 0.;
    }
}
