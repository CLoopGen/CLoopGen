#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int n;
    unsigned long u[607];
} zuf_state_t;

extern  unsigned long zuf_randmax;
extern long i;
extern long j;
extern long k;
extern long l;
extern long m;
extern double x;
extern double y;
extern long ii;
extern long jj;
extern zuf_state_t *state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Access elements of u with a fixed stride of 3 (mod 607 to stay in bounds)
    // This creates non-consecutive, strided writes, which may affect cache behavior.
    // The outer loop still runs 607 times to preserve total work.
    for (ii = 0; ii < 607; ++ii) {
        long idx = (ii * 3) % 607;  // Stride of 3 with wrap-around
        x = 0.;
        y = 0.5;
        for (jj = 1; jj <= 24; ++jj) {
            m = i * j % 179 * k % 179;
            i = j;
            j = k;
            k = m;
            l = (l * 53 + 1) % 169;
            if (l * m % 64 >= 32) {
                x += y;
            }
            y *= 0.5;
        }
        state->u[idx] = (unsigned long)(x * zuf_randmax);
    }
}
