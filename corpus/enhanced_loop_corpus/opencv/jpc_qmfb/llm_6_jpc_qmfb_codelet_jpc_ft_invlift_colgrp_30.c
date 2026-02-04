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
    jpc_fix_t temp;
    for (i = 0; i < 16; ++i) {
        temp = (lptr2[0] + lptr2[stride]) >> 1;
        hptr2[0] += temp;
        ++lptr2;
        ++hptr2;
    }
}
