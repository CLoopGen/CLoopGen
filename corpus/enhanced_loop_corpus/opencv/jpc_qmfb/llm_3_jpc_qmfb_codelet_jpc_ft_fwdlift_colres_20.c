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
    jpc_fix_t *lptr_base = lptr2;
    jpc_fix_t *hptr_base = hptr2;
    for (i = 0; i < numcols; ++i) {
        ptrdiff_t idx = (i * 2);
        hptr_base[idx] -= (lptr_base[idx] + lptr_base[idx + stride]) >> 1;
    }
}
