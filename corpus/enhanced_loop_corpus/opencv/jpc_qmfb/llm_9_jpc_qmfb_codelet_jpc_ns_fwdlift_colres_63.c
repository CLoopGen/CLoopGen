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
int step = 2;
for (i = 0; i < numcols; i += step) {
    jpc_fix_big_t scale = (jpc_fix_big_t)(((jpc_fix_t)(2. * (0.443506852043971) * ((double)(((jpc_fix_t)(1)) << 13)))));
    lptr2[0] = (jpc_fix_t)((lptr2[0]) + (((scale * hptr2[0]) + (1 << 12)) >> 13));
    if (i + 1 < numcols) {
        lptr2[1] = (jpc_fix_t)((lptr2[1]) + (((scale * hptr2[1]) + (1 << 12)) >> 13));
    }
    lptr2 += step;
    hptr2 += step;
}
}
