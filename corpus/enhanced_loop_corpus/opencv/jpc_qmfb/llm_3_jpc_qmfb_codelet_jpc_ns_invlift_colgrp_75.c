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
    int offset = 15 - i; // Reverse consecutive access
    ((hbase[offset]) = ((hbase[offset]) + ((-(((jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (0.88291107553093395)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(lbase[offset]))) >> (13))))))));
}
}
