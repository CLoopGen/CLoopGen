#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t* lptr_local = lptr2;
    jpc_fix_t* hptr_local = hptr2;
    jpc_fix_big_t coeff = (jpc_fix_big_t)((-1.5861343420599241) * ((double)(((jpc_fix_t)(1)) << 13)));
    for (i = 0; i < 16; ++i) {
        hptr_local[i] = hptr_local[i] + (jpc_fix_t)((coeff * (jpc_fix_big_t)(lptr_local[i] + lptr_local[i + stride])) >> 13);
    }
    lptr2 = lptr_local + 16;
    hptr2 = hptr_local + 16;
}
