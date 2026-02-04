#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        int local_iy = iy + i * incY; // Eliminate loop-carried dependency on iy update
        Y[local_iy] = 0.;
        // Removed sequential dependency on iy by computing index directly
    }
    iy += N * incY; // Update iy once after loop (if needed, though not observable in loop)
}
