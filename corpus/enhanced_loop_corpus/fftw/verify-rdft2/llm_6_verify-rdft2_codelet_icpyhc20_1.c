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
for (i = 0; i < n / 2 + 1; ++i) {
    R temp_r = rb[2 * i];
    R temp_i = ib[2 * i];
    ra[as * i] = temp_r;
    ia[as * i] = temp_i;
}
}
