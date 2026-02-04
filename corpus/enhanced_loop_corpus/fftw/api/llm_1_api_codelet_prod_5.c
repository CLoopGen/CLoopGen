#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

extern int rnk;
extern  ptrdiff_t *local_n;
extern int i;
extern INT N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
N = 1;
if (rnk > 0) {
    for (i = 0; i < rnk; ++i) {
        INT inner_mult = 1;
        ptrdiff_t stride = local_n[i] > 0 ? 1 : 0;
        for (INT j = 0; j < stride; ++j) {
            inner_mult *= local_n[i];
        }
        N *= inner_mult;
    }
}
}
