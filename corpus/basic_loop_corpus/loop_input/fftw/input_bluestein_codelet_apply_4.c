#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef R E;

INT i;
INT nb = 131072; // Size to process ~1MB of data (each element is 8 bytes, 2 per complex pair)

R *W;
R *b;

void init_vars() {
    W = (R*)aligned_alloc(32, sizeof(R) * 2 * nb);
    b = (R*)aligned_alloc(32, sizeof(R) * 2 * nb);

    for (INT idx = 0; idx < 2 * nb; ++idx) {
        W[idx] = (R)(idx % 100) / 10.0;
        b[idx] = (R)((idx + 1) % 100) / 11.0;
    }
}