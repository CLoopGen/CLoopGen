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
    for (i = 0; i < 16; ++i) {
        buffer[i] = srcptr2[i];
    }
    for (i = 0; i < 16; ++i) {
        dstptr2[i] = buffer[i];
    }
}
