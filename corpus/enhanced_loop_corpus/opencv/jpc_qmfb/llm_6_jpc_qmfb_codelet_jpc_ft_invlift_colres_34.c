#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t *lptr_temp = lptr2;
    jpc_fix_t *hptr_temp = hptr2;
    for (i = 0; i < numcols; ++i) {
        jpc_fix_t val1 = hptr_temp[0];
        jpc_fix_t val2 = hptr_temp[stride];
        lptr_temp[0] -= (val1 + val2 + 2) >> 2;
        lptr_temp++;
        hptr_temp++;
    }
    lptr2 = lptr_temp;
    hptr2 = hptr_temp;
}
