#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (numcols <= 0) return;
    jpc_fix_t hval = hptr2[0];
    for (i = 0; i < numcols; ++i) {
        jpc_fix_big_t product = ((jpc_fix_big_t)(-0.105960237145921996)) * ((jpc_fix_t)(1) << 13);
        jpc_fix_t correction = (jpc_fix_t)((product * (jpc_fix_big_t)(hval)) >> 13);
        lptr2[i] = lptr2[i] + correction;
    }
    lptr2 += numcols;
    hptr2 += numcols;
}
