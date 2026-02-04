#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern jpc_fix_t *srcptr2;
extern jpc_fix_t *dstptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    jpc_fix_t sum = 0;
    for (i = 0; i < numcols; ++i) {
        sum += srcptr2[i];
        dstptr2[i] = sum;
    }
}
