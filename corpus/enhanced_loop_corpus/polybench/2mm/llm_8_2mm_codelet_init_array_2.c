#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nl;
extern double C[900][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nj; i++) {
    double temp = 0.0;
    for (j = 0; j < nl; j++) {
        temp = (double)((i * (j + 5) + 2) % nl);
        C[i][j] = temp / nl * temp / nl;  // Increased arithmetic intensity: square of normalized value
    }
}
}
