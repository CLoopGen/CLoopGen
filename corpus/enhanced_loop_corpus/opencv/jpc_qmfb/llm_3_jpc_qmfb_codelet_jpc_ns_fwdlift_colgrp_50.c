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
    int offset = (i & 7) * 2; // Access pattern: repeated even indices in a small window (consecutive with reuse)
    jpc_fix_t temp = (jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)((((0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(((hptr2[offset]) + (hptr2[offset + 1]))))) >> (13));
    lptr2[offset] += temp;
}
}
