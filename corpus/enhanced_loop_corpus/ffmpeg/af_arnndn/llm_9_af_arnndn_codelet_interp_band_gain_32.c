#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t eband5ms[];
extern float *g;
extern  float *bandE;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 22 - 2; i += 2) {
    const int band_size1 = (eband5ms[i + 1] - eband5ms[i]) << 2;
    const int band_size2 = (eband5ms[i + 2] - eband5ms[i + 1]) << 2;
    int offset1 = eband5ms[i] << 2;
    int offset2 = eband5ms[i + 1] << 2;

    for (int j = 0; j < band_size1; j++) {
        float frac = (float)j / band_size1;
        g[offset1 + j] = (1.F - frac) * bandE[i] + frac * bandE[i + 1];
    }

    for (int j = 0; j < band_size2; j++) {
        float frac = (float)j / band_size2;
        g[offset2 + j] = (1.F - frac) * bandE[i + 1] + frac * bandE[i + 2];
    }
}
}
