#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; ++i) {
    int forward_idx = i;
    int backward_idx = 15 - i;
    jpc_fix_t temp_l_sum = lptr2[forward_idx] + lptr2[backward_idx];
    ((hptr2[forward_idx]) = ((hptr2[forward_idx]) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)((((-1.5861343420599241)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(temp_l_sum))) >> (13))))));
}
}
