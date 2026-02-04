#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t prev_val = 0;
    for (i = 0; i < 16; ++i) {
        jpc_fix_t current_input = (i == 0) ? hptr2[0] : prev_val;
        hptr2[0] = ((jpc_fix_t)((((jpc_fix_big_t)(current_input)) * ((jpc_fix_big_t)(((jpc_fix_t)((((1. / 1.62578613134411)) * ((double)(((jpc_fix_t)(1)) << (13))))))))) >> (13)));
        prev_val = hptr2[0];
        ++hptr2;
    }
}
