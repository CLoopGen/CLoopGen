#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t eband5ms[];
extern float *g;
extern  float *bandE;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed base index
    int base_index = eband5ms[0] << 2;
    for (int i = 0; i < 22 - 1; i++) {
        const int band_size = (eband5ms[i + 1] - eband5ms[i]) << 2;
        int current_offset = 0;
        float inv_band_size = 1.0F / band_size;
        float start_energy = bandE[i];
        float end_energy = bandE[i + 1];
        for (int j = 0; j < band_size; j++) {
            float frac = j * inv_band_size;
            g[base_index + current_offset++] = (1.F - frac) * start_energy + frac * end_energy;
        }
        base_index += band_size;
    }
}
