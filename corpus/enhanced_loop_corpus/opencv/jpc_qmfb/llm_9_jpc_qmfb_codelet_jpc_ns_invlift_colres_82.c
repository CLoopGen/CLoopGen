#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const jpc_fix_t factor = (jpc_fix_t)((1. / (1. / 1.23017410558578)) * (1 << 13));
    const int unroll_factor = 4;
    int limit = (numcols / unroll_factor) * unroll_factor;
    for (i = 0; i < limit; i += unroll_factor) {
        lptr2[0] = (jpc_fix_t)(((jpc_fix_big_t)lptr2[0] * factor) >> 13);
        lptr2[1] = (jpc_fix_t)(((jpc_fix_big_t)lptr2[1] * factor) >> 13);
        lptr2[2] = (jpc_fix_t)(((jpc_fix_big_t)lptr2[2] * factor) >> 13);
        lptr2[3] = (jpc_fix_t)(((jpc_fix_big_t)lptr2[3] * factor) >> 13);
        lptr2 += unroll_factor;
    }
    for (; i < numcols; ++i) {
        lptr2[0] = (jpc_fix_t)(((jpc_fix_big_t)lptr2[0] * factor) >> 13);
        ++lptr2;
    }
}
