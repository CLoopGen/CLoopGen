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
    // Variant 2: Consecutive Reverse Access from the end of arrays
    int idx;
    jpc_fix_t *ltemp = lptr2 + numcols - 1;
    jpc_fix_t *htemp = hptr2 + numcols - 1;
    for (i = 0; i < numcols; ++i) {
        ((htemp[0]) = ((htemp[0]) + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (0.88291107553093395)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(ltemp[0]))) >> (13))))))));
        --ltemp;
        --htemp;
    }
}
