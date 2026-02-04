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
    jpc_fix_t *l1, *l2, *h;
    l1 = lptr2;
    l2 = lptr2 + stride;
    h = hptr2;
    for (i = 0; i < 16; ++i) {
        h[i] -= (l1[i] + l2[i]) >> 1;
    }
}
