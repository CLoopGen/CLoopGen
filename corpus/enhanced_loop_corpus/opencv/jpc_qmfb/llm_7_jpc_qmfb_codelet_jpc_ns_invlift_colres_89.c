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
    jpc_fix_t *local_lptr = lptr2;
    jpc_fix_t *local_hptr = hptr2;
    jpc_fix_big_t acc = 0;
    const jpc_fix_big_t factor = (jpc_fix_big_t)(2. * 0.88291107553093395 * (1LL << 13));

    for (i = 0; i < numcols; ++i) {
        acc += ((jpc_fix_big_t)(local_lptr[0])) * factor;
        ++local_lptr;
    }

    local_lptr = lptr2;
    for (i = 0; i < numcols; ++i) {
        hptr2[0] = hptr2[0] - ((jpc_fix_t)((acc >> (13 + numcols-1)))); 
        ++local_lptr;
        ++hptr2;
    }

    lptr2 = local_lptr;
    hptr2 = local_hptr + numcols;
}
