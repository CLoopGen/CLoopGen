#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t *local_hptr = hptr2;
    jpc_fix_t factor = (jpc_fix_t)((((1. / 1.62578613134411)) * ((double)(((jpc_fix_t)(1)) << (13)))));
    for (i = 0; i < numcols; ++i) {
        local_hptr[0] = ((jpc_fix_t)((((jpc_fix_big_t)(local_hptr[0])) * ((jpc_fix_big_t)(factor))) >> (13)));
        ++local_hptr;
    }
    hptr2 = local_hptr;
}
