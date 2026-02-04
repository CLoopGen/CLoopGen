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
    float inv_band_size = 1.0F / band_size;
    float delta_E = (bandE[i + 1] - bandE[i]) * inv_band_size;
    float base_val = bandE[i];
    int offset = eband5ms[i] << 2;
    for (int j = 0; j < band_size; j++) {
        float frac = j * inv_band_size;
        g[offset + j] = base_val + frac * delta_E;
    }
}
}
