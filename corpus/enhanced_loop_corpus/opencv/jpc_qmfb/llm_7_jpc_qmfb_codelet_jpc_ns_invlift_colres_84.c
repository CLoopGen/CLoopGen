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
    jpc_fix_t* l_temp = lptr2;
    jpc_fix_t* h_temp = hptr2;
    jpc_fix_big_t coef = (jpc_fix_big_t)(((jpc_fix_t)((2. * 0.443506852043971) * ((double)(((jpc_fix_t)(1)) << 13)))));
    for (i = 0; i < numcols; ++i) {
        jpc_fix_big_t product = coef * (jpc_fix_big_t)(h_temp[i]);
        l_temp[i] = l_temp[i] - ((jpc_fix_t)(product >> 13));
    }
    lptr2 += numcols;
    hptr2 += numcols;
}
