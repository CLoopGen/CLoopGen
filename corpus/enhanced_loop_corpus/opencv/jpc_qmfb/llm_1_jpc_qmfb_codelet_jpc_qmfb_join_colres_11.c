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
    int outer = numcols / 2;
    int remainder = numcols % 2;
    for (i = 0; i < outer; ++i) {
        *dstptr2 = *srcptr2;
        ++dstptr2;
        ++srcptr2;
        *dstptr2 = *srcptr2;
        ++dstptr2;
        ++srcptr2;
    }
    for (i = 0; i < remainder; ++i) {
        *dstptr2 = *srcptr2;
        ++dstptr2;
        ++srcptr2;
    }
}
