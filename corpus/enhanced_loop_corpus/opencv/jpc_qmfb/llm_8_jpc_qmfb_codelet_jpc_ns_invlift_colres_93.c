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
    for (i = 0; i < numcols; ++i) {
        jpc_fix_big_t temp1 = ((jpc_fix_big_t)(lptr2[0])) << 1;
        jpc_fix_big_t temp2 = ((jpc_fix_big_t)(lptr2[0])) * 3;
        hptr2[0] = hptr2[0] - (jpc_fix_t)((temp1 + temp2) >> 1);
        ++hptr2;
        ++lptr2;
    }
}
