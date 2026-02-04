#include <stdio.h>

#include <inttypes.h>

extern int M;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // Access elements in pairs to improve spatial locality and enable potential vectorization
    int k;
    for (k = 0; k <= M - 1; k += 2) {
        mmx[0][k]     = imx[0][k]     = dmx[0][k]     = -987654321;
        mmx[0][k + 1] = imx[0][k + 1] = dmx[0][k + 1] = -987654321;
    }
    // Handle remaining element if M+1 is odd
    if ((M + 1) % 2 == 1) {
        mmx[0][M] = imx[0][M] = dmx[0][M] = -987654321;
    }
}
