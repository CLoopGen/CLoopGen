#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index permutation via modulo and offset
    int *temp_left = left;
    int *temp_q = q;
    for (i = 0; i < ni; ++i) {
        int idx = (i * 3 + 1) % ni; // pseudo-randomized access pattern
        temp_left[idx] = temp_q[idx];
    }
}
