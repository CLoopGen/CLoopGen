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
for (i = 0; i < numcols; i += 2) {
    int idx1 = i;
    int idx2 = i + 1;
    if (idx1 < numcols) {
        ((hptr2[idx1]) = ((hptr2[idx1]) + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (-1.5861343420599241)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(lptr2[idx1]))) >> (13))))))));
    }
    if (idx2 < numcols) {
        ((hptr2[idx2]) = ((hptr2[idx2]) + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (-1.5861343420599241)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(lptr2[idx2]))) >> (13))))))));
    }
}
}
