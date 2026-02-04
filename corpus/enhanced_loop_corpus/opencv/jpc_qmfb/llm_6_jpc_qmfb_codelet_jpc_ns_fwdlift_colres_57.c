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
    jpc_fix_t* local_lptr = lptr2;
    jpc_fix_t* local_hptr = hptr2;
    for (i = 0; i < numcols; ++i) {
        jpc_fix_big_t temp = ((jpc_fix_big_t)(-0.105960237145921996)) * ((jpc_fix_t)(1) << 13);
        jpc_fix_t scaled_val = (jpc_fix_t)((temp * (jpc_fix_big_t)(local_hptr[0])) >> 13);
        local_lptr[0] = local_lptr[0] + scaled_val;
        ++local_lptr;
        ++local_hptr;
    }
    lptr2 = local_lptr;
    hptr2 = local_hptr;
}
