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
for (i = 8; i < findex + 11; i++) {
    const float a = temp[i] * synthesis_high[0];
    const float b = temp[i] * synthesis_high[1];
    const float c = temp[i] * synthesis_high[2];
    const float d = temp[i] * synthesis_high[3];
    const float e = temp[i] * synthesis_high[4];
    output[2 * i - 13] += a;
    output[2 * i - 12] += b;
    output[2 * i - 11] += c;
    output[2 * i - 10] += d;
    output[2 * i - 9] += e;
    output[2 * i - 8] += d;
    output[2 * i - 7] += c;
    output[2 * i - 6] += b;
    output[2 * i - 5] += a;
}

}
