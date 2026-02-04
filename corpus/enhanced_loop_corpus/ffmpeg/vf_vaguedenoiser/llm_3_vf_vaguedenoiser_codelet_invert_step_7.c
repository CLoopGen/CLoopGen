#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float synthesis_low[7];
extern float *output;
extern float *temp;
extern int i;
extern int findex;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with indirect indexing via lookup table for output positions
    // Precomputed offsets for each access relative to base index (2*i)
    static const int offsets[] = { -13, -12, -11, -10, -9, -8, -7 };
    const int num_accesses = 7;
    for (i = 9; i < findex + 11; i++) {
        const float t_val = temp[i];
        const float coeffs[] = {
            t_val * synthesis_low[0], // a
            t_val * synthesis_low[1], // b
            t_val * synthesis_low[2], // c
            t_val * synthesis_low[3]  // d
        };
        const float values[] = { coeffs[0], coeffs[1], coeffs[2], coeffs[3], coeffs[2], coeffs[1], coeffs[0] };
        
        // Indirect and strided write using fixed offset table
        const int base_idx = 2 * i;
        for (int j = 0; j < num_accesses; j++) {
            output[base_idx + offsets[j]] += values[j];
        }
    }
}
