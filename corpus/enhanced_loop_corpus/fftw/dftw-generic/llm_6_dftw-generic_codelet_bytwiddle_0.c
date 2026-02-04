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
            R *pr = rio + ms * im + rs * ir;
            R *pi = iio + ms * im + rs * ir;
            E xr = *pr;
            E xi = *pi;
            E wr = W[2 * im + (2 * (m - 1)) * ir - 2];
            E wi = W[2 * im + (2 * (m - 1)) * ir - 1];
            // Introduce a temporary accumulator to create additional RAW dependencies and eliminate direct WAW on *pr and *pi early
            E temp_pr = xr * wr + xi * wi;
            E temp_pi = xi * wr - xr * wi;
            *pr = temp_pr;
            *pi = temp_pi;
        }
    }
    rio += vs;
    iio += vs;
}
}
