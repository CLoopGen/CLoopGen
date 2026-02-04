#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const jpc_fix_t scale = (jpc_fix_t)((1. / (1. / 1.62578613134411)) * (1 << 13));
    for (i = 0; i < numcols; ++i) {
        jpc_fix_big_t product = (jpc_fix_big_t)(hptr2[0]) * (jpc_fix_big_t)(scale);
        jpc_fix_t result = (jpc_fix_t)(product >> 13);
        hptr2[0] = result;
        ++hptr2;
    }
}
