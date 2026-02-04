#include <stdio.h>

#include <inttypes.h>

extern int M;
extern int **mmx;
extern int **imx;
extern int **dmx;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2
    // First pass: even indices, second pass: odd indices
    // This simulates a non-unit stride access pattern which may affect cache performance
    int k;
    // First handle even indices
    for (k = 0; k <= M; k += 2) {
        mmx[0][k] = imx[0][k] = dmx[0][k] = -987654321;
    }
    // Then handle odd indices
    for (k = 1; k <= M; k += 2) {
        mmx[0][k] = imx[0][k] = dmx[0][k] = -987654321;
    }
}
