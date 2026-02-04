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
    const int band_size = (eband5ms[i + 1] - eband5ms[i]) << 2;
    if (band_size <= 0) continue;
    for (int j = 0; j < band_size; j++) {
        float frac = (float)j / band_size;
        g[(eband5ms[i] << 2) + j] = (1.F - frac) * bandE[i] + frac * bandE[i + 1];
    }
}
}
