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
for (i = 0; i < numcols; ++i) {
    int forward_idx = i;
    int backward_idx = numcols - 1 - i;
    jpc_fix_t temp_h_sum = (jpc_fix_t)((hptr2[forward_idx] + hptr2[backward_idx]));
    ((lptr2[forward_idx]) = ((lptr2[forward_idx]) + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)((((-0.052980118572960998)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(temp_h_sum))) >> (13))))))));
}
}
