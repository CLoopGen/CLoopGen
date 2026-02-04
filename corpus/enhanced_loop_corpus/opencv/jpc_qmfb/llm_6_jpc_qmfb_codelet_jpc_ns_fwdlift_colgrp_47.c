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
    jpc_fix_t *l1 = lptr2;
    jpc_fix_t *h1 = hptr2;
    for (i = 0; i < 16; ++i) {
        jpc_fix_big_t temp = ((jpc_fix_big_t)(l1[0]) + (l1[stride]));
        h1[0] = h1[0] + (jpc_fix_t)(((((jpc_fix_big_t)(((jpc_fix_t)((((0.88291107553093395)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * temp) >> (13)));
        ++l1;
        ++h1;
    }
}
