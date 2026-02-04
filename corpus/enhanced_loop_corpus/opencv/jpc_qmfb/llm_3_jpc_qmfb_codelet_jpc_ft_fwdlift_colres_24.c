#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive block access using pointer arithmetic with array indexing
    jpc_fix_t *lbase = lptr2;
    jpc_fix_t *hbase = hptr2;
    for (i = 0; i < numcols; ++i) {
        lbase[i] += (hbase[i] + 1) >> 1;
    }
}
