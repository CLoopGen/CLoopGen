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
    for (im = mb; im < me; ++im) {
        for (ir = 1; ir < r; ++ir) {
            INT data_offset = ms * im + rs * ir;
            INT w_offset = 2 * im + (2 * (m - 1)) * ir - 2;
            E xr = *(rio + data_offset);
            E xi = *(iio + data_offset);
            E wr = *(W + w_offset);
            E wi = *(W + w_offset + 1);
            *(rio + data_offset) = xr * wr + xi * wi;
            *(iio + data_offset) = xi * wr - xr * wi;
        }
    }
    rio += vs;
    iio += vs;
}
}
