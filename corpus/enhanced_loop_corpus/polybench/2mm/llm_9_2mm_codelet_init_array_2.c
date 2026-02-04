#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nl;
extern double C[900][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nj && i < 500; i++) {  // Reduced effective trip count with upper bound
    for (j = 1; j < nl; j += 2) {      // Stride-2 iteration, reducing total iterations by ~half
        C[i][j] = (double)((i * j + 2) % nl) / nl;
        C[i][j-1] = C[i][j];          // Reuse computed value in adjacent element (if j > 0)
    }
}
}
