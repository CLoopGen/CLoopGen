#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t *lbase = lptr2;
    jpc_fix_t *hbase = hptr2;
    for (i = 0; i < 16; ++i) {
        int offset = (i & 3) * 4; // Simulate non-linear access pattern using modulo-like indexing
        lbase[offset] += (hbase[offset] + hbase[offset + stride] + 2) >> 2;
    }
}
