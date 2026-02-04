#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real bench_complex[2];

typedef bench_complex C;

extern C *A;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            ((A[i])[1]) = 0.;
            ((A[i + 1])[1]) = 0.;
        } else {
            ((A[i])[1]) = 0.;
        }
    }
}
