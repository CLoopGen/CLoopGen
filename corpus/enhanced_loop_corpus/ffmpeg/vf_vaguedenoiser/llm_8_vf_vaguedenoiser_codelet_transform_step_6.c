#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float analysis_high[7];
extern float *input;
extern float *output;
extern  int low_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 10; i < 10 + low_size; i += 2) {
    const float a1 = input[2 * i - 12] * analysis_high[0];
    const float b1 = input[2 * i - 11] * analysis_high[1];
    const float c1 = input[2 * i - 10] * analysis_high[2];
    const float d1 = input[2 * i - 9]  * analysis_high[3];
    const float e1 = input[2 * i - 8]  * analysis_high[2];
    const float f1 = input[2 * i - 7]  * analysis_high[1];
    const float g1 = input[2 * i - 6]  * analysis_high[0];
    output[i + low_size] = a1 + b1 + c1 + d1 + e1 + f1 + g1;

    if (i + 1 < 10 + low_size) {
        const float a2 = input[2 * (i+1) - 12] * analysis_high[0];
        const float b2 = input[2 * (i+1) - 11] * analysis_high[1];
        const float c2 = input[2 * (i+1) - 10] * analysis_high[2];
        const float d2 = input[2 * (i+1) - 9]  * analysis_high[3];
        const float e2 = input[2 * (i+1) - 8]  * analysis_high[2];
        const float f2 = input[2 * (i+1) - 7]  * analysis_high[1];
        const float g2 = input[2 * (i+1) - 6]  * analysis_high[0];
        output[(i+1) + low_size] = a2 + b2 + c2 + d2 + e2 + f2 + g2;
    }
}
}
