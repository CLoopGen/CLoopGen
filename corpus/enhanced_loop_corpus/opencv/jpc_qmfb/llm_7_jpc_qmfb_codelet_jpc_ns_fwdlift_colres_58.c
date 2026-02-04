#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (numcols <= 0) return;
    jpc_fix_big_t coeff = (jpc_fix_big_t)((-0.052980118572960998) * (1LL << 13));
    jpc_fix_t* restrict lptr = lptr2;
    jpc_fix_t* restrict hptr = hptr2;
    int stride_val = stride;
    int n = numcols;

    lptr[0] += (jpc_fix_t)(((coeff * (jpc_fix_big_t)(hptr[0] + hptr[stride_val])) >> 13));
    for (i = 1; i < n; ++i) {
        jpc_fix_t prev_hsum = hptr[i - 1] + hptr[i - 1 + stride_val];
        jpc_fix_t curr_hsum = hptr[i] + hptr[i + stride_val];
        jpc_fix_big_t delayed_contrib = (coeff * prev_hsum) >> 13;
        lptr[i] = lptr[i] + (jpc_fix_t)delayed_contrib;
    }
    lptr2 += n;
    hptr2 += n;
}
