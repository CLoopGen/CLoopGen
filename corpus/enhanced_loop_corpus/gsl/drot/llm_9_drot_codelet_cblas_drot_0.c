#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *X;
extern  int incX;
extern double *Y;
extern  int incY;
extern  double c;
extern  double s;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: perform only one arithmetic operation per element
// and skip every other element to halve the trip count
int limit = N / 2;
for (i = 0; i < limit; i++) {
    X[ix] = c * X[ix];  // Only scale X, no interaction with Y
    ix += 2 * incX;
    iy += 2 * incY;  // Y is not accessed, but indices still advanced for consistency
}
}
