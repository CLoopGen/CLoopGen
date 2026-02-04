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
    // Variant 1: Consecutive Memory Access with Reverse Iteration
    // The array u is now accessed in reverse order (consecutive backward traversal)
    // All computations remain the same, only the loop index direction changes.
    for (ii = 606; ii >= 0; --ii) {
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
        state->u[ii] = (unsigned long)(x * zuf_randmax);
    }
}
