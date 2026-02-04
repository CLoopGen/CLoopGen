#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int8_t filt[64];
extern  int16_t *in;
extern int32_t sample;
extern int16_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling by factor 2
    // Access pattern: in[0], in[2], ..., in[62] and filt[0], filt[2], ..., filt[62]
    sample = 0; // Reset sample to ensure clean accumulation
    int16_t j;
    for (j = 0; j < 64; j += 2) {
        sample += in[j] * filt[j];
        if (j + 1 < 64) {
            sample += in[j + 1] * filt[j + 1];
        }
    }
}
