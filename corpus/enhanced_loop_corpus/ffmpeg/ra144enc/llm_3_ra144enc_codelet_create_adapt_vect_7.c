#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *vect;
extern  int16_t *cb;
extern int lag;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    // Simulate indirect access by precomputing indices in a local array on stack
    int indices[40];
    for (int j = 0; j < 40 - lag; j++) {
        indices[j] = j;
    }
    for (i = 0; i < 40 - lag; i++) {
        int idx = indices[i]; // Simulated indirect access
        vect[lag + idx] = cb[idx];
    }
}
