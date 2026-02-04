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
    if (numcols > 0) {
        i = 0;
        for (; i < numcols / 2; ++i) {
            ((hptr2[0]) = ((hptr2[0]) + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)((((-1.5861343420599241)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(((lptr2[0]) + (lptr2[stride]))))) >> (13))))))));
            ++lptr2;
            ++hptr2;
        }
        for (; i < numcols; ++i) {
            ((hptr2[0]) = ((hptr2[0]) + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)((((-1.5861343420599241)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(((lptr2[0]) + (lptr2[stride]))))) >> (13))))))));
            ++lptr2;
            ++hptr2;
        }
    }
}
