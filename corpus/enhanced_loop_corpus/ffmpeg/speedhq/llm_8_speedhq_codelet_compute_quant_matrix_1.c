#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint8_t ff_zigzag_direct[64];
extern  uint8_t unscaled_quant_matrix[64];
extern int *output;
extern int qscale;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        int idx = ff_zigzag_direct[i];
        output[i*2] = unscaled_quant_matrix[idx] * qscale;
        output[i*2 + 1] = (unscaled_quant_matrix[idx] + 1) * qscale;
    }
}
