#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float synthesis_high[9];
extern float *output;
extern float *temp;
extern int i;
extern int findex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 8; i < findex + 11 && i < 18; i++) {
    const float t = temp[i];
    const float coeffs[5] = {
        t * synthesis_high[0],
        t * synthesis_high[1],
        t * synthesis_high[2],
        t * synthesis_high[3],
        t * synthesis_high[4]
    };

    int base_index = 2 * i - 13;
    output[base_index + 0] += coeffs[0]; // a
    output[base_index + 1] += coeffs[1]; // b
    output[base_index + 2] += coeffs[2]; // c
    output[base_index + 3] += coeffs[3]; // d
    output[base_index + 4] += coeffs[4]; // e
    output[base_index + 5] += coeffs[3]; // d
    output[base_index + 6] += coeffs[2]; // c
    output[base_index + 7] += coeffs[1]; // b
    output[base_index + 8] += coeffs[0]; // a
}
}
