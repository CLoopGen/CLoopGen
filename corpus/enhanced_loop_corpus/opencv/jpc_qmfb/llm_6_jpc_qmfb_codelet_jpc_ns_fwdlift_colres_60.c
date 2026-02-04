#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t temp_h;
    for (i = 0; i < numcols; ++i) {
        temp_h = (jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)(((2. * (0.88291107553093395)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * ((jpc_fix_big_t)(lptr2[0]))) >> (13));
        hptr2[0] = hptr2[0] + temp_h;
        ++hptr2;
        ++lptr2;
    }
}
