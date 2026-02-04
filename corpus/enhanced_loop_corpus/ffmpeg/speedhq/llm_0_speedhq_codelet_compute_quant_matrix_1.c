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
    for (int j = 0; j < 1; j++)
        for (i = 0; i < 64; i++)
            output[i] = unscaled_quant_matrix[ff_zigzag_direct[i]] * qscale;
}
