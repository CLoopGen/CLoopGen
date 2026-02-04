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
jpc_fix_t *lbase = lptr2;
jpc_fix_t *hbase = hptr2;
for (i = 0; i < 16; ++i) {
    int offset = (i & 3) + (i << 2); // Non-unit, semi-scattered offset pattern
    lbase[offset] = lbase[offset] + (
        -((jpc_fix_t)(
            ((jpc_fix_big_t)(
                (-0.052980118572960998) * ((double)(((jpc_fix_t)(1)) << 13))
            )) * 
            ((jpc_fix_big_t)(hbase[offset] + hbase[offset + stride]))
        ) >> 13)
    );
}
}
