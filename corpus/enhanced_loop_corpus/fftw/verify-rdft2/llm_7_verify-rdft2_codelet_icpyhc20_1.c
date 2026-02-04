#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real R;

extern int i;
extern int n;
extern int as;
extern R *ra;
extern R *ia;
extern R *rb;
extern R *ib;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
R prev_ra = 0.0;
R prev_ia = 0.0;
for (i = 0; i < n / 2 + 1; ++i) {
    R curr_r = rb[2 * i] + prev_ra;
    R curr_i = ib[2 * i] + prev_ia;
    ra[as * i] = curr_r;
    ia[as * i] = curr_i;
    prev_ra = curr_r;
    prev_ia = curr_i;
}
}
