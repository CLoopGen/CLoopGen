#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double R;
typedef ptrdiff_t INT;
typedef R E;

R *ro;
R *io;
INT i;
INT n;
INT os;
R *w;
R *b;

void init_vars() {
    n = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
    os = 1;

    ro = (R*)aligned_alloc(32, n * os * sizeof(R));
    io = (R*)aligned_alloc(32, n * os * sizeof(R));
    w  = (R*)aligned_alloc(32, 2 * n * sizeof(R));
    b  = (R*)aligned_alloc(32, 2 * n * sizeof(R));

    for (INT idx = 0; idx < 2 * n; ++idx) {
        b[idx] = (R)(idx % 127) / 64.0;
    }
    for (INT idx = 0; idx < 2 * n; ++idx) {
        w[idx] = (R)((idx + 31) % 97) / 89.0;
    }
    for (INT idx = 0; idx < n * os; ++idx) {
        ro[idx] = 0.0;
        io[idx] = 0.0;
    }
}