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
    for (i = 0; i < 8; ++i) {
        jpc_fix_big_t lval0 = lptr2[0];
        jpc_fix_big_t lval1 = lptr2[1];
        jpc_fix_big_t hval = hptr2[0];
        jpc_fix_big_t coef = (jpc_fix_big_t)((((jpc_fix_t)(2. * (-1.5861343420599241) * ((double)(((jpc_fix_t)(1)) << 13))))));

        hval += (-((coef * lval0) >> 13));
        hval += (-((coef * lval1) >> 13));

        hptr2[0] = (jpc_fix_t)hval;
        hptr2++;
        lptr2 += 2;
    }
}
