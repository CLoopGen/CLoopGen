#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t qcelp_rate_full_codebook[128];
extern  float *gain;
extern float *cdn_vector;
extern int i;
extern int j;
extern uint16_t cbseed;
extern float tmp_gain;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - traverse qcelp_rate_full_codebook with a fixed stride
    const int stride = 3; // Arbitrary stride for indirect-like pattern within bounds
    for (i = 0; i < 4; i++) {
        tmp_gain = gain[i] * 0.01;
        for (j = 0; j < 40; j++) {
            int index = (cbseed + j * stride) & 127; // Strided access into codebook
            *cdn_vector++ = tmp_gain * qcelp_rate_full_codebook[index];
        }
        cbseed += 40 * stride; // Advance seed accordingly to maintain consistency
    }
}
