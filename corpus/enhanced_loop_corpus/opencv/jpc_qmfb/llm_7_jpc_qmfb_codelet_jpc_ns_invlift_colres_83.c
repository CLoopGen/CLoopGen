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
    if (numcols <= 0) return;
    jpc_fix_t *base = hptr2;
    jpc_fix_t scale = (jpc_fix_t)(((1. / (1. / 1.62578613134411)) * ((double)(((jpc_fix_t)(1)) << (13)))));
    jpc_fix_big_t scaled_val = ((jpc_fix_big_t)(base[0])) * ((jpc_fix_big_t)(scale));
    base[0] = (jpc_fix_t)(scaled_val >> 13);
    for (i = 1; i < numcols; ++i) {
        jpc_fix_big_t prev = ((jpc_fix_big_t)(base[i - 1])); 
        jpc_fix_big_t curr = ((jpc_fix_big_t)(base[i])) * ((jpc_fix_big_t)(scale)) + (prev >> 14); 
        base[i] = (jpc_fix_t)(curr >> 13);
    }
    hptr2 += numcols;
}
