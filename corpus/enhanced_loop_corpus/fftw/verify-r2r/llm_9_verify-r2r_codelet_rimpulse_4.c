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
for (i = 0; i < N; i += 2) {
    if (i + 1 < N) {
        inA[i] = 0.;
        inA[i + 1] = 0.;
    } else {
        inA[i] = 0.;
    }
}
}
