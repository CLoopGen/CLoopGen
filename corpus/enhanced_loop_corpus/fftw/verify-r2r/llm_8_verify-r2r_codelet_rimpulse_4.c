#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double bench_real;

typedef bench_real R;

extern R *inA;
extern int N;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i0;
for (i = 0; i < N; ++i) {
    inA[i] = 0.;
    for (i0 = 1; i0 < 4; ++i0) {
        inA[i] += (bench_real)(i0 * i0) / (bench_real)(i + 1);
    }
}
}
