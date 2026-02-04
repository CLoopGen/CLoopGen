#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        lptr2[0] -= (hptr2[0] + hptr2[stride] + hptr2[2*stride] + hptr2[3*stride] + 4) >> 3;
        lptr2[1] -= (hptr2[1] + hptr2[stride+1] + 2) >> 2;
        lptr2 += 2;
        hptr2 += 2;
    }
}
