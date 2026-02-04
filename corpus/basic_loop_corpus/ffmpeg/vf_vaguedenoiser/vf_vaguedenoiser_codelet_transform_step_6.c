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
for (i = 10; i < 10 + low_size; i++) {
    const float a = input[2 * i - 12] * analysis_high[0];
    const float b = input[2 * i - 11] * analysis_high[1];
    const float c = input[2 * i - 10] * analysis_high[2];
    const float d = input[2 * i - 9] * analysis_high[3];
    const float e = input[2 * i - 8] * analysis_high[2];
    const float f = input[2 * i - 7] * analysis_high[1];
    const float g = input[2 * i - 6] * analysis_high[0];
    output[i + low_size] = a + b + c + d + e + f + g;
}

}
