#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern  double *X;
extern double *Y;
extern int i;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = m; i + 3 < N; i += 4) {
        int offsets[4] = {0, 1, 2, 3};
        for (int k = 0; k < 4; k++) {  // Increased loop depth and replaced direct unrolling with indexed access
            Y[i + offsets[k]] += alpha * X[i + offsets[k]];
        }
    }
}
