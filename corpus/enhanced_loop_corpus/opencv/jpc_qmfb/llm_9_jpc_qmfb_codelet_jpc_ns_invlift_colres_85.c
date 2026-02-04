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
    int step = 2;
    for (i = 0; i < numcols; i += step) {
        jpc_fix_big_t hsum1 = (jpc_fix_big_t)(hptr2[0] + hptr2[stride]);
        jpc_fix_big_t hsum2 = (i + 1 < numcols) ? (jpc_fix_big_t)(hptr2[1] + hptr2[stride + 1]) : hsum1;

        jpc_fix_t corr1 = (jpc_fix_t)(((((jpc_fix_t)((((0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << 13)))))) * hsum1) >> 13);
        jpc_fix_t corr2 = (jpc_fix_t)(((((jpc_fix_t)((((0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << 13)))))) * hsum2) >> 13);

        lptr2[0] = lptr2[0] - corr1;
        if (i + 1 < numcols) {
            lptr2[1] = lptr2[1] - corr2;
        }

        lptr2 += step;
        hptr2 += step;
    }
}
