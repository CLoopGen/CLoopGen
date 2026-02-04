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
    jpc_fix_t temp[16];
    for (i = 0; i < 16; ++i) {
        temp[i] = lptr2[i];
    }
    for (i = 0; i < 16; ++i) {
        hptr2[i] += temp[i];
    }
}
