#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t *ltemp = lptr2;
    jpc_fix_t *htemp = hptr2;
    jpc_fix_t accum = 0;
    for (i = 0; i < 16; ++i) {
        accum += ltemp[0];
        ++ltemp;
    }
    for (i = 0; i < 16; ++i) {
        htemp[0] -= accum;
        ++htemp;
    }
    lptr2 = ltemp;
    hptr2 = htemp;
}
