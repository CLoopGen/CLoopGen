#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern jpc_fix_t *srcptr2;
extern jpc_fix_t *dstptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    // Assuming a fixed indirect pattern: reverse order access
    for (i = 0; i < numcols; ++i) {
        int idx = numcols - 1 - i;  // Reverse indexing
        *(dstptr2 + i) = *(srcptr2 + idx);
    }
}
