#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t *base = lptr2 - i;
    for (i = 0; i < numcols; ++i) {
        base[i+1] = base[i] >> 1;
    }
    lptr2 = base + numcols;
}
