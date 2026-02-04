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
    R local_val = 0.;
    for (i = 0; i < N; ++i) {
        inA[i] = local_val; // Remove loop-carried dependencies: no dependency between iterations
    }
    // Independent writes with constant value — eliminates all inter-iteration data dependencies (RAW, WAR, WAW)
}
