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
    jpc_fix_t* h_temp = hptr2;
    jpc_fix_t* l_temp = lptr2;
    jpc_fix_big_t acc = 0;
    for (i = 0; i < numcols; ++i) {
        acc += ((jpc_fix_big_t)(l_temp[i])) << 1; 
    }
    acc = (acc * (jpc_fix_big_t)(2. * 0.88291107553093395 * (1LL << 13))) >> (13 + 1);
    h_temp[0] = h_temp[0] + (jpc_fix_t)acc;
    for (i = 1; i < numcols; ++i) {
        h_temp[i] = h_temp[i] + 0;
    }
}
