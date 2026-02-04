#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef R E;

INT n;
E *x;
R *w;
INT i;
E rr;
E ri;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 million elements to target ~0.01 sec runtime
    n = (INT)(data_size / sizeof(E));
    if (n % 2 != 0) n--; // Ensure n is even so that i+i < n and pointer arithmetic stays in bounds

    x = (E*)aligned_alloc(32, data_size);
    w = (R*)aligned_alloc(32, data_size);

    for (INT j = 0; j < n; ++j) {
        x[j] = 1.0 + (j % 7); 
        w[j] = 2.0 + (j % 5); 
    }

    rr = 0.0;
    ri = 0.0;
}