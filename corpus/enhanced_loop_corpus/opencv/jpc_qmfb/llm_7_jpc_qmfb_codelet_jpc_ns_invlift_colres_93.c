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
    jpc_fix_t *hptr_local = hptr2;
    jpc_fix_t *lptr_local = lptr2;
    for (i = 0; i < numcols; ++i) {
        hptr_local[0] = hptr_local[0] + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (-1.5861343420599241)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(lptr_local[0]))) >> (13))))));
        ++hptr_local;
        ++lptr_local;
    }
    hptr2 = hptr_local;
    lptr2 = lptr_local;
}
