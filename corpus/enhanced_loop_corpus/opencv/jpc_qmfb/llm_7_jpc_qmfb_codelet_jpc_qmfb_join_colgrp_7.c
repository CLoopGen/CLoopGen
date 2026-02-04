#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern jpc_fix_t *srcptr2;
extern jpc_fix_t *dstptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t buffer[16];
    int j;
    for (j = 0; j < 16; ++j) {
        buffer[j] = srcptr2[j];
    }
    for (j = 0; j < 16; ++j) {
        dstptr2[j] = buffer[j];
    }
}
