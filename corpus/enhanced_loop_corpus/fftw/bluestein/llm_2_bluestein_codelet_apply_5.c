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
for (i = 0; i < n; ++i) {
    INT idx_b_real = 2 * i;
    INT idx_b_imag = 2 * i + 1;
    INT idx_w_real = 2 * i;
    INT idx_w_imag = 2 * i + 1;
    INT idx_out_r = i * os;
    INT idx_out_i = i * os;

    E xi = b[idx_b_real];
    E xr = b[idx_b_imag];
    E wr = w[idx_w_real];
    E wi = w[idx_w_imag];

    ro[idx_out_r] = xr * wr + xi * wi;
    io[idx_out_i] = xi * wr - xr * wi;
}
}
