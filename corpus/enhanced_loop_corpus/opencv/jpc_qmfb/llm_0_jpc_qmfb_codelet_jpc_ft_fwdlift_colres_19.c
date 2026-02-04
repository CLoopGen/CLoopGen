#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 1; ++outer) {
    for (i = 0; i < numcols; ++i) {
        hptr2[0] -= lptr2[0];
        ++hptr2;
        ++lptr2;
    }
}
}
