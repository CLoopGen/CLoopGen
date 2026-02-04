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
    if (numcols <= 0) return;
    jpc_fix_t *local_lptr = lptr2;
    jpc_fix_t scaled_value = (jpc_fix_t)(((1. / (1. / 1.23017410558578)) * ((double)(((jpc_fix_t)(1)) << (13)))));
    jpc_fix_big_t acc = 0;
    for (i = 0; i < numcols; ++i) {
        acc += ((jpc_fix_big_t)(local_lptr[0])) * ((jpc_fix_big_t)(scaled_value));
        local_lptr[0] = (jpc_fix_t)((acc >> 13) & 0xFFFFFFFF); 
        acc >>= 1; 
        ++local_lptr;
    }
    lptr2 = local_lptr;
}
