#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < numcols; i += 2) {
        if (i + 1 < numcols) {
            hptr2[0] = ((jpc_fix_t)((((jpc_fix_big_t)(hptr2[0])) * ((jpc_fix_big_t)(((jpc_fix_t)((((1. / 1.62578613134411)) * ((double)(((jpc_fix_t)(1)) << (13))))))))) >> (13)));
            hptr2[1] = ((jpc_fix_t)((((jpc_fix_big_t)(hptr2[1])) * ((jpc_fix_big_t)(((jpc_fix_t)((((1. / 1.62578613134411)) * ((double)(((jpc_fix_t)(1)) << (13))))))))) >> (13)));
            hptr2 += 2;
        } else {
            hptr2[0] = ((jpc_fix_t)((((jpc_fix_big_t)(hptr2[0])) * ((jpc_fix_big_t)(((jpc_fix_t)((((1. / 1.62578613134411)) * ((double)(((jpc_fix_t)(1)) << (13))))))))) >> (13)));
            ++hptr2;
        }
    }
}
