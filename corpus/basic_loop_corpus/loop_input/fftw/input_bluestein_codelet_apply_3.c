#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef R E;

INT i;
INT nb = 134217728; // 134M elements -> ~1GB array (b has 2*nb elements), loop runs ~0.01s on modern CPU
R *b;

void init_vars() {
    b = (R*)aligned_alloc(32, 2 * nb * sizeof(R));
    if (!b) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    i = 0;
}