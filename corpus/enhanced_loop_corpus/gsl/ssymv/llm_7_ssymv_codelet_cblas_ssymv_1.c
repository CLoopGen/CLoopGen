#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern float *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_beta = beta;
    for (i = 0; i < N; i++) {
        int offset = i * incY; // Remove loop-carried dependency on iy by computing directly
        Y[offset] *= local_beta; // Eliminate WAW and WAR on iy; no mutation of shared state across iterations
    }
    iy += N * incY; // Update iy once after loop (not loop-carried)
}
