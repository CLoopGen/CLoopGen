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
    jpc_fix_t *local_lptr = lptr2;
    jpc_fix_t factor = (jpc_fix_t)(((1. / (1. / 1.23017410558578)) * ((double)(((jpc_fix_t)(1)) << (13)))));
    for (i = 0; i < numcols; ++i) {
        jpc_fix_big_t temp = ((jpc_fix_big_t)(local_lptr[0])) * ((jpc_fix_big_t)(factor));
        local_lptr[0] = (jpc_fix_t)(temp >> 13);
        ++local_lptr;
    }
    lptr2 = local_lptr;
}
