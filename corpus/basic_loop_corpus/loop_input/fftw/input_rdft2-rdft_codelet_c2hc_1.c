#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;

INT n;
R *rio;
R *iio;
INT is;
R *r;
INT i;

void init_vars() {
    n = 65536; 
    is = 1;

    rio = (R*)aligned_alloc(32, n * sizeof(R));
    iio = (R*)aligned_alloc(32, n * sizeof(R));
    r = (R*)aligned_alloc(32, n * sizeof(R));

    for (INT idx = 0; idx < n; ++idx) {
        rio[idx] = (R)(idx * 2);
        iio[idx] = (R)(idx * 3);
        r[idx] = 0.0;
    }
}