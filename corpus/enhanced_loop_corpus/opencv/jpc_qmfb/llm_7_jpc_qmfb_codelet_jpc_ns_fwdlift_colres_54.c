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
    jpc_fix_t *local_hptr = hptr2;
    jpc_fix_t *local_lptr = lptr2;
    jpc_fix_big_t coeff = (jpc_fix_big_t)((-3.1722686841198482) * ((double)(((jpc_fix_t)(1)) << 13)));
    for (i = 0; i < numcols; ++i) {
        local_hptr[0] = local_hptr[0] + ((jpc_fix_t)((coeff * local_lptr[0]) >> 13));
        ++local_hptr;
        ++local_lptr;
    }
    hptr2 = local_hptr;
    lptr2 = local_lptr;
}
