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
    for (i = 0; i < 64; i += 2) {
        output[i] = (unscaled_quant_matrix[ff_zigzag_direct[i]] * qscale) >> 1;
        if (i + 1 < 64)
            output[i + 1] = (unscaled_quant_matrix[ff_zigzag_direct[i + 1]] * qscale * 3) / 2;
    }
}
