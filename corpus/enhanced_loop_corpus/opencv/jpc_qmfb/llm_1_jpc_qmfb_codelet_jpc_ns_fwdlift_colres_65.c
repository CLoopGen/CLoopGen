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
if (numcols > 0) {
    for (int i1 = 0; i1 < numcols / 2; ++i1) {
        ((lptr2[0]) = ((lptr2[0]) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(hptr2[0]))) >> (13))))));
        ++lptr2;
        ++hptr2;
    }
    for (int i2 = numcols / 2; i2 < numcols; ++i2) {
        ((lptr2[0]) = ((lptr2[0]) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(hptr2[0]))) >> (13))))));
        ++lptr2;
        ++hptr2;
    }
}
}
