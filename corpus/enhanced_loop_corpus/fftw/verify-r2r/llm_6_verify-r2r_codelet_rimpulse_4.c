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
    R temp = 0.;
    for (i = 0; i < N; ++i) {
        temp = inA[i] + temp; // Introduce RAW dependency: temp depends on previous iteration
        inA[i] = temp;       // WAW: inA[i] written after potential prior write; WAR: inA[i] read before write in next use
    }
}
