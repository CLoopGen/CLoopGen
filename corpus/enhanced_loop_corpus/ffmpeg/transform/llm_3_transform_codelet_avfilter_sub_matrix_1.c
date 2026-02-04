#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *m1;
extern  float *m2;
extern float *result;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access)
    int index_map[9] = {8, 7, 6, 5, 4, 3, 2, 1, 0}; // Reverse order access
    for (i = 0; i < 9; i++) {
        int idx = index_map[i];
        result[idx] = m1[idx] - m2[idx];
    }
}
