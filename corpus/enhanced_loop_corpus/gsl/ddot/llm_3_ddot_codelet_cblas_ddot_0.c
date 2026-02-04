#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double *X;
extern  int incX;
extern  double *Y;
extern  int incY;
extern double r;
extern int i;
extern int ix;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal and larger stride
    // Use stride of 2 and traverse from the end to beginning
    int stride = 2;
    int limit = N / stride;
    int baseX = (N - 1) * incX;
    int baseY = (N - 1) * incY;
    for (i = 0; i < limit; i++) {
        r += X[baseX - i * incX * stride] * Y[baseY - i * incY * stride];
    }
}
