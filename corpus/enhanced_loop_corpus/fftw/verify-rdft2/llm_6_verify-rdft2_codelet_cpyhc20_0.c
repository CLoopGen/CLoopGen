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
    R temp_r, temp_i;
    for (i = 0; i < n / 2 + 1; ++i) {
        temp_r = ra[as * i];
        temp_i = ia[as * i];
        rb[2 * i] = temp_r;
        ib[2 * i] = temp_i;
    }
}
