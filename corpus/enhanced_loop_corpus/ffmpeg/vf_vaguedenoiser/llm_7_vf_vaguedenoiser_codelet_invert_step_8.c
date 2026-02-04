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
float prev_a = 0.0f;
for (i = 8; i < findex + 11; i++) {
    const float current_temp = temp[i];
    const float a = current_temp * synthesis_high[0];
    const float b = current_temp * synthesis_high[1];
    const float c = current_temp * synthesis_high[2];
    const float d = current_temp * synthesis_high[3];
    const float e = current_temp * synthesis_high[4];
    const int offset = 2 * i - 13;
    output[offset]     += prev_a;
    output[offset + 1] += b;
    output[offset + 2] += c;
    output[offset + 3] += d;
    output[offset + 4] += e;
    output[offset + 5] += d;
    output[offset + 6] += c;
    output[offset + 7] += b;
    output[offset + 8] += a;
    prev_a = a;
}
}
