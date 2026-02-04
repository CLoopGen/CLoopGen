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
    jpc_fix_t temp = 0;
    for (i = 0; i < 16; ++i) {
        temp = (hptr2[i] + 1) >> 1;
        lptr2[i] += temp;
    }
}
