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
    int temp[64];
    for (i = 0; i < 64; i++)
        temp[i] = unscaled_quant_matrix[ff_zigzag_direct[i]] * qscale;
    for (i = 0; i < 64; i++)
        output[i] = temp[i];
}
