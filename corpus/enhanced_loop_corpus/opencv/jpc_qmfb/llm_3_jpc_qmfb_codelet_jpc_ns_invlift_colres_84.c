#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Reverse Memory Access
    // Process array elements from the end to the beginning with unit stride.
    // Maintains good locality but reverses traversal order.
    jpc_fix_t *ltemp = lptr2 + numcols - 1;
    jpc_fix_t *htemp = hptr2 + numcols - 1;

    for (i = 0; i < numcols; ++i) {
        ((ltemp[0]) = ((ltemp[0]) + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(htemp[0]))) >> (13))))))));
        --ltemp;
        --htemp;
    }

    // Update original pointers if side effects are expected (optional, based on use case).
    // Here we assume the function is self-contained and pointer updates are local.
}
