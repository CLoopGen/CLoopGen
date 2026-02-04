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
for (i = 0; i < n / 4 + 1; ++i) {
    ra[as * i] = rb[4 * i];
    ia[as * i] = ib[4 * i];
    ra[as * i + 1] = rb[4 * i + 2];
    ia[as * i + 1] = ib[4 * i + 2];
}
}
