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
    jpc_fix_t* lptr_local = lptr2;
    jpc_fix_t* hptr_local = hptr2;
    jpc_fix_t acc = 0;
    for (i = 0; i < 16; ++i) {
        jpc_fix_big_t combined_input = (jpc_fix_big_t)(lptr_local[0] + lptr_local[stride]);
        jpc_fix_t contribution = (jpc_fix_t)((((jpc_fix_big_t)(((jpc_fix_t)((((0.88291107553093395)) * ((double)(((jpc_fix_t)(1)) << (13)))))))) * combined_input) >> 13);
        acc += contribution;
        hptr_local[0] = acc;
        ++lptr_local;
        ++hptr_local;
    }
    lptr2 = lptr_local;
    hptr2 = hptr_local;
}
