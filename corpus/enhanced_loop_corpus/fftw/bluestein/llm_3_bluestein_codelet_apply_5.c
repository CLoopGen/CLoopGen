#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *ro;
extern R *io;
extern INT i;
extern INT n;
extern INT os;
extern R *w;
extern R *b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT *indices = (INT*)malloc(n * sizeof(INT));
for (INT j = 0; j < n; ++j) indices[j] = j;
for (i = 0; i < n; ++i) {
    INT shuffled_idx = indices[n - 1 - i]; // reverse access order
    E xi = b[2 * shuffled_idx];
    E xr = b[2 * shuffled_idx + 1];
    E wr = w[2 * shuffled_idx];
    E wi = w[2 * shuffled_idx + 1];
    ro[i * os] = xr * wr + xi * wi;
    io[i * os] = xi * wr - xr * wi;
}
free(indices);
}
