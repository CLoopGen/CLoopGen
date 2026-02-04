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
    for (ii = 0; ii < 607; ++ii) {
        x = 0.;
        y = 0.5;
        long prev_i = i, prev_j = j, prev_k = k;
        long local_l = l;
        for (jj = 1; jj <= 24; ++jj) {
            long m = prev_i * prev_j % 179 * prev_k % 179;
            prev_i = prev_j;
            prev_j = prev_k;
            prev_k = m;
            local_l = (local_l * 53 + 1) % 169;
            double update = (local_l * m % 64 >= 32) ? y : 0.0;
            x += update;
            y *= 0.5;
        }
        state->u[ii] = (unsigned long)(x * zuf_randmax);
        i = prev_i;
        j = prev_j;
        k = prev_k;
        l = local_l;
    }
}
