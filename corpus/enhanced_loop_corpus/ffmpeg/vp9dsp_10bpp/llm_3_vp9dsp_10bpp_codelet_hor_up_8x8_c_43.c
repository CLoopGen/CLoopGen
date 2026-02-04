#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t v[14];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided read access with fixed offset indexing
    // Simulate indirect-like access by introducing a base index array (emulated via stride)
    // Use a step of 1 but precompute indices to simulate non-unit stride in reads
    int idx[3];
    for (i = 0; i < 8 - 2; i++) {
        idx[0] = i;
        idx[1] = i + 1;
        idx[2] = i + 2;
        v[i * 2]     = (left[idx[0]] + left[idx[1]] + 1) >> 1;
        v[i * 2 + 1] = (left[idx[0]] + left[idx[1]] * 2 + left[idx[2]] + 2) >> 2;
    }
}
