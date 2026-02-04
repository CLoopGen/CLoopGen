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
    jpc_fix_t temp_accum = 0;
    for (i = 0; i < numcols; ++i) {
        temp_accum += (hptr2[i] + hptr2[i + stride] + 2) >> 2;
        if ((i % 4) == 3 || i == numcols - 1) {
            lptr2[(i / 4) * 4] -= temp_accum;
            temp_accum = 0;
        }
    }
    lptr2 += numcols;
    hptr2 += numcols;
}
