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
    rb[2 * i] = ra[as * i];
    ib[2 * i] = ia[as * i];
    rb[2 * i + 1] = ra[as * i + 1];
    ib[2 * i + 1] = ia[as * i + 1];
}
}
