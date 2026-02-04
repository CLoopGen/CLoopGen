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
extern int jx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float prev_temp = 0.0f;
for (j = 0; j < lenX; j++) {
    const float temp = alpha * X[jx] + prev_temp * 0.1f; // Introduce WAW and RAW dependency: temp now depends on previous iteration
    if (temp != 0.) {
        const int i_min = (j > U ? j - U : 0);
        const int i_max = ((lenY) < (j + L + 1) ? (lenY) : (j + L + 1));
        int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) + i_min * incY;
        float accumulator = 0.0f;
        for (i = i_min; i < i_max; i++) {
            accumulator += temp * A[lda * j + (U + i - j)]; // Accumulate before write to break WAR/WAW in Y
            iy += incY;
        }
        // Apply accumulated result to first relevant Y element (simulated use)
        if (i_min < lenY) {
            int first_iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY))) + i_min * incY;
            Y[first_iy] += accumulator;
        }
    }
    prev_temp = temp; // Loop-carried dependence introduced
    jx += incX;
}
}
