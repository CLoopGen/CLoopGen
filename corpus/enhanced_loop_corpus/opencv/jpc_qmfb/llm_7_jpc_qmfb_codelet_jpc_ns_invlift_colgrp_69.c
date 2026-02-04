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
    jpc_fix_t prev_result = 0;
    for (i = 0; i < 16; ++i) {
        jpc_fix_t scaled_factor = ((jpc_fix_t)(((1. / (1. / 1.62578613134411)) * ((double)(((jpc_fix_t)(1)) << (13))))));
        jpc_fix_big_t product = ((jpc_fix_big_t)(hptr2[0] + prev_result)) * ((jpc_fix_big_t)(scaled_factor)); // RAW dependency: uses previous result
        hptr2[0] = ((jpc_fix_t)(product >> 13));
        prev_result = hptr2[0]; // Creates loop-carried dependency (prev_result used in next iteration)
        ++hptr2;
    }
}
