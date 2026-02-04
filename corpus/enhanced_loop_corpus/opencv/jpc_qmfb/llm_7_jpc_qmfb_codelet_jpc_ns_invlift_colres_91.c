#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t* lptr_local = lptr2;
    jpc_fix_t* hptr_local = hptr2;
    jpc_fix_big_t coeff = (jpc_fix_big_t)(((-0.052980118572960998)) * ((double)(((jpc_fix_t)(1)) << 13)));
    for (i = 0; i < numcols; ++i) {
        jpc_fix_big_t h_val = (jpc_fix_big_t)(hptr_local[0] + hptr_local[stride]);
        jpc_fix_t correction = (jpc_fix_t)((-(coeff * h_val)) >> 13);
        lptr_local[0] += correction;
        ++lptr_local;
        ++hptr_local;
    }
    lptr2 = lptr_local;
    hptr2 = hptr_local;
}
