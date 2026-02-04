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
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_cache[1024]; // Local cache to store computed temp values to introduce WAW and WAR dependencies
    int k;
    for (j = 0; j < lenX; j++) {
        temp_cache[j] = alpha * X[ix]; // Write to temp_cache (WAW if unrolled, but sequential here)
        if (temp_cache[j] != 0.) {
            int iy = ((incY) > 0 ? 0 : ((lenY) - 1) * (-(incY)));
            for (i = 0; i < lenY; i++) {
                Y[iy] += temp_cache[j] * A[lda * j + i]; // Read temp_cache[j] after write (RAW dependency on temp_cache)
                iy += incY;
            }
        }
        ix += incX;
    }
}
