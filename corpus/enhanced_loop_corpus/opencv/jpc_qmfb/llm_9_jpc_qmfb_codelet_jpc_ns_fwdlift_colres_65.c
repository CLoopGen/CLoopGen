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
    int step = 2;
    for (i = 0; i < numcols; i += step) {
        // Unroll the loop by processing two elements per iteration
        if (i + 1 < numcols) {
            // First element
            lptr2[0] = lptr2[0] + (jpc_fix_t)((((jpc_fix_big_t)((jpc_fix_t)(2. * 0.443506852043971 * ((double)((jpc_fix_t)(1) << 13))))) * (jpc_fix_big_t)(hptr2[0])) >> 13);
            // Second element
            lptr2[1] = lptr2[1] + (jpc_fix_t)((((jpc_fix_big_t)((jpc_fix_t)(2. * 0.443506852043971 * ((double)((jpc_fix_t)(1) << 13))))) * (jpc_fix_big_t)(hptr2[1])) >> 13);
            lptr2 += 2;
            hptr2 += 2;
        } else {
            // Handle leftover element if numcols is odd
            lptr2[0] = lptr2[0] + (jpc_fix_t)((((jpc_fix_big_t)((jpc_fix_t)(2. * 0.443506852043971 * ((double)((jpc_fix_t)(1) << 13))))) * (jpc_fix_big_t)(hptr2[0])) >> 13);
            ++lptr2;
            ++hptr2;
        }
    }
}
