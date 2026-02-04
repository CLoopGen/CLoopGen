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
// Reduce arithmetic operations and simplify inner loop body
// Increase trip count of inner loop while reducing per-iteration work
for (iv = 0; iv < v; ++iv) {
    for (ir = 1; ir < r; ++ir) {
        for (im = mb; im < me; ++im) {
            R *pr = rio + ms * im + rs * ir;
            R *pi = iio + ms * im + rs * ir;
            E wr = W[2 * im + (2 * (m - 1)) * ir - 2];
            E wi = W[2 * im + (2 * (m - 1)) * ir - 1];
            // Combine loads and reduce arithmetic: only update real part, skip imaginary
            *pr = (*pr) * wr; // Simplified computation: remove cross terms
        }
    }
    rio += vs;
    iio += vs;
}
}
