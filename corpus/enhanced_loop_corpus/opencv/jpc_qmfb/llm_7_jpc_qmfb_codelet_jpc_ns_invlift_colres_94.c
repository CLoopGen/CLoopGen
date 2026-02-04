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
    jpc_fix_t* lptr2_local = lptr2;
    jpc_fix_t* hptr2_local = hptr2;
    jpc_fix_big_t coeff = (jpc_fix_big_t)((-1.5861343420599241) * ((jpc_fix_t)1 << 13));
    for (i = 0; i < numcols; ++i) {
        jpc_fix_big_t product = coeff * (lptr2_local[0] + lptr2_local[stride]);
        hptr2_local[0] = hptr2_local[0] - (jpc_fix_t)(product >> 13);
        ++lptr2_local;
        ++hptr2_local;
    }
    lptr2 = lptr2_local;
    hptr2 = hptr2_local;
}
