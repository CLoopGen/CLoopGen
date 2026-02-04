#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;

INT n = 131072;          
INT npad = 262144;        
R *omega;                 
INT i;

void init_vars() {
    omega = (R*)aligned_alloc(64, sizeof(R) * npad);
    if (!omega) {
        exit(1);
    }

    for (INT idx = 0; idx < npad; ++idx) {
        omega[idx] = (R)(idx % 1000) + 0.5;
    }
}