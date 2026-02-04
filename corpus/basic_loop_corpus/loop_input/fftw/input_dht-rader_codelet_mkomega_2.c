#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef R E;

INT npad = 16777216; // ~134 MB for double array (16M * 8 bytes)

R *omega = NULL;

INT i = 0;

void init_vars() {
    omega = (R*)aligned_alloc(64, npad * sizeof(R));
    if (!omega) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}