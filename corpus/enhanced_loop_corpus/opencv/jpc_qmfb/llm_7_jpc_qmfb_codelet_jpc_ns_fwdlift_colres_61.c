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
    jpc_fix_t acc = 0;
    for (i = 0; i < numcols; ++i) {
        jpc_fix_big_t extended_val = (jpc_fix_big_t)l1[0];
        jpc_fix_big_t scaled = extended_val * 718; 
        acc += (jpc_fix_t)(scaled >> 12);
        h1[0] = h1[0] + acc;
        ++l1;
        ++h1;
    }
}
