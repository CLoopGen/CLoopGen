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
        jpc_fix_t temp1 = hptr2[0];
        jpc_fix_t temp2 = hptr2[stride];
        jpc_fix_t sum = temp1 + temp2 + 2;
        jpc_fix_t shift_val = sum >> 2;
        lptr2[0] -= shift_val;
        ++lptr2;
        ++hptr2;
    }
}
