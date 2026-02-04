#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double R;

typedef ptrdiff_t INT;

typedef R E;

extern R *rio;
extern R *iio;
extern INT iv;
extern INT ir;
extern INT im;
extern INT r;
extern INT rs;
extern INT m;
extern INT mb;
extern INT me;
extern INT ms;
extern INT v;
extern INT vs;
extern  R *W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (iv = 0; iv < v; ++iv) {
    for (ir = 1; ir < r; ++ir) {
        for (im = mb; im < me; ++im) {
            INT idx = ms * im + rs * ir;
            R *pr = rio + idx;
            R *pi = iio + idx;
            E xr = pr[0];
            E xi = pi[0];
            INT w_idx = 2 * im + (2 * (m - 1)) * ir - 2;
            E wr = W[w_idx];
            E wi = W[w_idx + 1];
            pr[0] = xr * wr + xi * wi;
            pi[0] = xi * wr - xr * wi;
        }
    }
    rio += vs;
    iio += vs;
}
}
