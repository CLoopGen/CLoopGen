#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef R E;

INT i;
INT nb = 134217728; // 134217728 elements -> 2 * nb = 268435456, ~2GB for double array
R *W;

void init_vars() {
    W = (R*)aligned_alloc(32, 2 * nb * sizeof(R));
    if (!W) {
        exit(1);
    }
}