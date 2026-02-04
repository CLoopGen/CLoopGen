#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *I = NULL;
INT i = 0;
INT N = 0;

void init_vars() {
    N = 134217728; // 134M elements, ~1GB for double array (8 bytes per element)
    I = (R*)calloc(N, sizeof(R));
    if (!I) {
        exit(1);
    }
}