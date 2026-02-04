#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t eband5ms[];
extern float *g;
extern  float *bandE;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 22 - 1; i++) {
    const int band_start = eband5ms[i] << 2;
    const int band_end = eband5ms[i + 1] << 2;
    const int band_size = band_end - band_start;
    for (int j = 0; j < band_size; j++) {
        if (bandE[i] == 0.0F && bandE[i + 1] == 0.0F) {
            g[band_start + j] = 0.0F;
        } else {
            float frac = (float)j / band_size;
            g[band_start + j] = (1.F - frac) * bandE[i] + frac * bandE[i + 1];
        }
    }
}
}
