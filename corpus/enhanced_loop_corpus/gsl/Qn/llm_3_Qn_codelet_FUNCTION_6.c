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
    // Variant 2: Indirect memory access using an index array (simulated with arithmetic)
    for (i = 0; i < ni; ++i) {
        int idx = (i * 3 + 1) % ni;  // Pseudo-randomized indirect-like index within bounds
        left[idx] = q[idx];
    }
}
