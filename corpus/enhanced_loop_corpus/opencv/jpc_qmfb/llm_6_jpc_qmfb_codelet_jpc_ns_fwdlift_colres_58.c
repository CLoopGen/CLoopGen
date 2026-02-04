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
    jpc_fix_big_t coeff = (jpc_fix_big_t)((-0.052980118572960998) * (1LL << 13));
    int i_local = 0;
    for (; i_local < numcols; ++i_local) {
        jpc_fix_t temp_sum = (jpc_fix_t)(hptr_local[0] + hptr_local[stride]);
        jpc_fix_big_t scaled = coeff * temp_sum;
        lptr_local[0] = lptr_local[0] + (jpc_fix_t)(scaled >> 13);
        ++lptr_local;
        ++hptr_local;
    }
    lptr2 = lptr_local;
    hptr2 = hptr_local;
}
