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
    jpc_fix_t* lbase = lptr2;
    jpc_fix_t* hbase = hptr2;
    for (i = 0; i < numcols; ++i) {
        jpc_fix_t val = (-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (-0.052980118572960998)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(hbase[i]))) >> (13)))));
        lbase[i] = lbase[i] + val;
    }
    lptr2 += numcols;
    hptr2 += numcols;
}
