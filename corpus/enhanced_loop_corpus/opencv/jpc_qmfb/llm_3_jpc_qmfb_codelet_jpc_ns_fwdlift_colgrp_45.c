#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
jpc_fix_t *ltemp = lptr2;
jpc_fix_t *htemp = hptr2;
for (i = 0; i < 16; ++i) {
    // Consecutive reverse access from the end of the original segment
    int rev_idx = 15 - i;
    ((ltemp[rev_idx]) = ((ltemp[rev_idx]) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (-0.052980118572960998)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(htemp[rev_idx]))) >> (13))))));
}
}
