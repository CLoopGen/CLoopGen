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
        float temp_bandE = bandE[i];
        float diff_bandE = bandE[i + 1] - temp_bandE;
        for (int j = 0; j < band_size; j++) {
            float frac = j * inv_band_size;
            g[(eband5ms[i] << 2) + j] = (1.F - frac) * temp_bandE + frac * (temp_bandE + diff_bandE);
        }
    }
}
