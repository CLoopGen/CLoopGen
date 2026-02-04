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
    for (i = 0; i < numcols; ++i) {
        hptr2[0] -= (lptr2[0] + lptr2[stride] + lptr2[stride * 2]) >> 2;
        hptr2[1] -= (lptr2[1] + lptr2[stride + 1]) >> 1;
        ++lptr2;
        ++hptr2;
    }
}
