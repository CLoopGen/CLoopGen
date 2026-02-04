#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *ri;
extern R *ii;
extern INT i;
extern INT n;
extern INT is;
extern R *w;
extern R *b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; ++i) {
    INT ri_idx = i * is;
    INT w_idx_base = 2 * i;
    INT b_idx_base = 2 * i;

    // Reorder computation to access w and b with unit stride indirectly via pointer arithmetic
    E xr = *(ri + ri_idx);
    E xi = *(ii + ri_idx);
    E wr = *(w + w_idx_base);
    E wi = *(w + w_idx_base + 1);

    // Store results using computed base indices for consecutive memory pattern in b
    *(b + b_idx_base) = xr * wr + xi * wi;
    *(b + b_idx_base + 1) = xi * wr - xr * wi;
}
}
