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
    int step = 2;
    for (i = 0; i < numcols; i += step) {
        jpc_fix_big_t coeff = (jpc_fix_big_t)(((jpc_fix_t)(2. * 0.443506852043971 * (1LL << 13))));
        lptr2[0] = lptr2[0] - ((coeff * hptr2[0]) >> 13);
        if (i + 1 < numcols) {
            lptr2[1] = lptr2[1] - ((coeff * hptr2[1]) >> 13);
        }
        lptr2 += step;
        hptr2 += step;
    }
}
