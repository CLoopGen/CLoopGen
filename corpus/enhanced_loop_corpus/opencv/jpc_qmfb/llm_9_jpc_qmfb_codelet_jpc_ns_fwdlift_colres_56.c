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
    for (i = 0; i < numcols / 2; ++i) {
        jpc_fix_big_t coeff = (jpc_fix_big_t)((jpc_fix_t)(-1.5861343420599241 * 2.0 * ((double)(((jpc_fix_t)(1)) << 13))));
        jpc_fix_t temp1 = (jpc_fix_t)((coeff * (jpc_fix_big_t)(lptr2[0])) >> 13);
        jpc_fix_t temp2 = (jpc_fix_t)((coeff * (jpc_fix_big_t)(lptr2[numcols/2])) >> 13);
        hptr2[0] += temp1;
        hptr2[numcols/2] += temp2;
        ++lptr2;
        ++hptr2;
    }
}
