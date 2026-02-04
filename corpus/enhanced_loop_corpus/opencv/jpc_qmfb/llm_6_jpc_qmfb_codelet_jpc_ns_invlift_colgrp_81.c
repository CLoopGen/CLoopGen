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
    jpc_fix_t temp_h0;
    for (i = 0; i < 16; ++i) {
        temp_h0 = hptr2[0];
        temp_h0 = temp_h0 - (jpc_fix_t)(((((jpc_fix_big_t)(-1.5861343420599241 * (1LL << 13))) * (jpc_fix_big_t)(lptr2[0])) >> 13));
        hptr2[0] = temp_h0;
        ++lptr2;
        ++hptr2;
    }
}
