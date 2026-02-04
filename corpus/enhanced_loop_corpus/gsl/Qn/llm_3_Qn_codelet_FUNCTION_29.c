#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *right;
extern int *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index array (simulated via pointer arithmetic)
    for (i = 0; i < ni; ++i) {
        int idx = i;
        right[idx] = p[idx];
    }
}
