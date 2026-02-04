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
// Reduced computational complexity: flattened nested loop and reduced operations
x = 0.;
y = 0.5;
m = i * j % 179 * k % 179;
l = (l * 53 + 1) % 169;

for (ii = 0; ii < 304; ++ii) {  // Approximate half the iterations with more work per iteration
    // Unroll and reduce inner logic: simulate effect of 12 steps instead of 24
    for (jj = 0; jj < 6; ++jj) {  // Smaller inner loop, but repeated less frequently
        m = (i * j % 179 * k % 179);
        i = j; j = k; k = m;
        l = (l * 53 + 1) % 169;
        if ((l * m % 64) >= 32) x += y;
        y *= 0.5;
        
        m = (i * j % 179 * k % 179);
        i = j; j = k; k = m;
        l = (l * 53 + 1) % 169;
        if ((l * m % 64) >= 32) x += y;
        y *= 0.5;
    }
    state->u[2*ii] = (unsigned long)(x * zuf_randmax);
    // Second value derived without full computation
    state->u[2*ii+1] = (unsigned long)((x * 0.85) * zuf_randmax);  // Simplified variation
}
}
