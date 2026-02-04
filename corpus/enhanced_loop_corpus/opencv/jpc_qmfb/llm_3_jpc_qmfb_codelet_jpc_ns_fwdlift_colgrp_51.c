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
jpc_fix_t *lbase = lptr2;
jpc_fix_t *hbase = hptr2;
for (i = 0; i < 16; ++i) {
    int offset = (i & 3) + ((i >> 2) * 8); // Indirect-like access: interleave indices (e.g., 0,1,2,3,8,9,10,11,...)
    ((lbase[offset]) = ((lbase[offset]) + (((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(hbase[offset]))) >> (13))))));
}
}
