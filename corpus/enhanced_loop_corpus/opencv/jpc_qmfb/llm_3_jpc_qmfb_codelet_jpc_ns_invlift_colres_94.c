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
    jpc_fix_t *l1 = lptr2;
    jpc_fix_t *h1 = hptr2;
    for (i = 0; i < numcols; ++i) {
        h1[i] = h1[i] + (
            -(jpc_fix_t)(
                ((jpc_fix_big_t)(
                    (-1.5861343420599241) * ((double)(((jpc_fix_t)(1)) << 13))
                )) * 
                ((jpc_fix_big_t)(l1[i] + l1[i + stride]))
            ) >> 13
        );
    }
}
