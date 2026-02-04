#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; ++i) {
    jpc_fix_big_t term1 = ((jpc_fix_big_t)(hptr2[0] + hptr2[stride]));
    jpc_fix_big_t term2 = ((jpc_fix_big_t)(hptr2[stride*2] + hptr2[stride*3]));
    jpc_fix_t corr = (jpc_fix_t)((((-0.052980118572960998)) * ((double)(((jpc_fix_t)(1)) << (13)))));
    lptr2[0] = lptr2[0] + (-((jpc_fix_t)((corr * term1) >> 13)));
    lptr2[1] = lptr2[1] + (-((jpc_fix_t)((corr * term2) >> 13)));
    lptr2 += 2;
    hptr2 += 4;
}
}
