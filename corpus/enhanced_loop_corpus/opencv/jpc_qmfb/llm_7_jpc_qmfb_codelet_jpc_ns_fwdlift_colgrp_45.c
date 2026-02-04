#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t acc = 0;
    for (i = 0; i < 16; ++i) {
        acc += hptr2[0];
        lptr2[0] = (jpc_fix_t)((jpc_fix_big_t)(lptr2[0]) + (((jpc_fix_big_t)(((jpc_fix_t)(-0.105960237145921996 * ((double)(((jpc_fix_t)(1)) << (13)))))) * ((jpc_fix_big_t)(acc))) >> (13)));
        ++lptr2;
        ++hptr2;
    }
}
