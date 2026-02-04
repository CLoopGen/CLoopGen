#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef R E;

INT n = 1 << 23; // Approximately 8MB for each of xr, xi (total ~16MB), gives reasonable runtime

R *xr;
R *xi;
INT xs = 1;
E *o;
INT i;
E sr = 0.0;
E si = 0.0;

void init_vars() {
    xr = (R*)aligned_alloc(32, n * sizeof(R));
    xi = (R*)aligned_alloc(32, n * sizeof(R));
    size_t o_size = (n / 2) * 4 * sizeof(E); // Over-allocate to ensure safety in loop
    o = (E*)aligned_alloc(32, o_size);

    for (INT idx = 0; idx < n; ++idx) {
        xr[idx] = (R)(rand() % 1000) / 10.0;
        xi[idx] = (R)(rand() % 1000) / 10.0;
    }

    sr = 0.0;
    si = 0.0;
}