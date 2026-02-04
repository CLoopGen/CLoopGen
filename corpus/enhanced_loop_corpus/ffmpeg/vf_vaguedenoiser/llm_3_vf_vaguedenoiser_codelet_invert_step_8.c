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
    // Variant 2: Strided memory access with fixed stride on output using pointer arithmetic
    // Use pointer induction variables with constant stride to traverse output
    float* out_ptr = &output[2 * 8 - 13]; // Initialize to first accessed location: 2*8 - 13 = 3
    for (i = 8; i < findex + 11; i++) {
        const float t = temp[i];
        const float a = t * synthesis_high[0];
        const float b = t * synthesis_high[1];
        const float c = t * synthesis_high[2];
        const float d = t * synthesis_high[3];
        const float e = t * synthesis_high[4];

        // Use strided access via pointer arithmetic (stride of 2 in index corresponds to linear increment in pointer)
        *(out_ptr + 0) += a;
        *(out_ptr + 1) += b;
        *(out_ptr + 2) += c;
        *(out_ptr + 3) += d;
        *(out_ptr + 4) += e;
        *(out_ptr + 5) += d;
        *(out_ptr + 6) += c;
        *(out_ptr + 7) += b;
        *(out_ptr + 8) += a;

        // Advance pointer by 2 positions (since 2*i increases by 2 each iteration)
        out_ptr += 2;
    }
}
