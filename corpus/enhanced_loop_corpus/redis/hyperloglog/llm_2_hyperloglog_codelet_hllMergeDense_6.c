#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_raw;
extern  uint8_t *reg_dense;
extern uint8_t val;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with unrolled accumulation
    // Instead of bit-level indexing into reg_dense, we process data in larger strides
    // and simulate a more sequential access pattern by precomputing byte indices.
    
    uint8_t *p = (uint8_t *)reg_dense;
    for (int i = 0; i < (1 << 14); i += 2) {
        // Precompute byte offsets for two iterations to promote spatial locality
        unsigned long byte0 = (i * 6) / 8;
        unsigned long fb0 = (i * 6) & 7;
        unsigned long fb8_0 = 8 - fb0;
        
        unsigned long byte1 = ((i + 1) * 6) / 8;
        unsigned long fb1 = ((i + 1) * 6) & 7;
        unsigned long fb8_1 = 8 - fb1;

        // Load required bytes for both i and i+1
        unsigned long b0_0 = p[byte0], b0_1 = p[byte0 + 1];
        unsigned long b1_0 = p[byte1], b1_1 = p[byte1 + 1];

        // Extract 6-bit values using shifted bit masks
        uint8_t val0 = ((b0_0 >> fb0) | (b0_1 << fb8_0)) & 0x3F;
        uint8_t val1 = ((b1_0 >> fb1) | (b1_1 << fb8_1)) & 0x3F;

        // Update reg_raw for both indices
        reg_raw[i] = (reg_raw[i] > val0) ? reg_raw[i] : val0;
        if (i + 1 < (1 << 14)) {
            reg_raw[i + 1] = (reg_raw[i + 1] > val1) ? reg_raw[i + 1] : val1;
        }
    }
}
