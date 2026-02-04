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
    jpc_fix_t* lptr_temp = lptr2;
    jpc_fix_t* hptr_temp = hptr2;
    for (i = 0; i < numcols; ++i) {
        jpc_fix_t temp_val = (hptr_temp[0] + hptr_temp[stride]);
        ((lptr_temp[0]) = ((lptr_temp[0]) + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)((((0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(temp_val))) >> (13))))))));
        ++lptr_temp;
        ++hptr_temp;
    }
    lptr2 = lptr_temp;
    hptr2 = hptr_temp;
}
