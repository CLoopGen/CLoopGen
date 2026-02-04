#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t eband5ms[];
extern float *g;
extern  float *bandE;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (reverse traversal with stride of 2 in output)
    // Write only to even indices in g, traversing band elements in reverse order within each segment
    for (int i = 0; i < 22 - 1; i++) {
        const int band_size = (eband5ms[i + 1] - eband5ms[i]) << 2;
        int base_g_index = (eband5ms[i] << 2) & ~1; // Align to even index
        float delta_e = bandE[i + 1] - bandE[i];
        for (int j = 0; j < band_size; j += 2) { // Stride of 2 in j
            float frac = (float)(band_size - 1 - j) / band_size; // Reverse access
            g[base_g_index + j] = (1.F - frac) * bandE[i] + frac * bandE[i + 1];
        }
    }
}
