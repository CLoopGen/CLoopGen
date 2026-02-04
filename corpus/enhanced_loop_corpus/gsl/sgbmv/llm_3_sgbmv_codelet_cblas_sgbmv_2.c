#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *A;
extern  int lda;
extern  float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int i;
extern int j;
extern int lenX;
extern int lenY;
extern int L;
extern int U;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < lenY; i++) {
    float temp = 0.;
    const int j_min = (i > L ? i - L : 0);
    const int j_max = ((lenX) < (i + U + 1) ? (lenX) : (i + U + 1));
    // Use indirect addressing via index array for X (simulating gather-like access)
    // Assume auxiliary array 'index_map' maps logical j to physical jx position
    // Here we simulate the effect without external declarations by computing indices
    int jx = ((incX) > 0 ? 0 : ((lenX) - 1) * (-(incX))) + j_min * incX;
    for (int idx = j_min; idx < j_max; idx++) {
        int addr_X = jx + (idx - j_min) * incX; // Simulated indirect stride calculation
        int addr_A = (L - i + idx) + i * lda;
        temp += X[addr_X] * A[addr_A];
    }
    Y[iy] += alpha * temp;
    iy += incY;
}
}
