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
for (i = 8; i < findex + 15; i += 2) {
    const float t = temp[i];
    const float a = t * synthesis_high[0];
    const float b = t * synthesis_high[1];
    const float c = t * synthesis_high[2];
    const float d = t * synthesis_high[3];
    const float e = t * synthesis_high[4];

    output[2 * i - 13] += a;
    output[2 * i - 12] += b;
    output[2 * i - 11] += c;
    output[2 * i - 10] += d;
    output[2 * i - 9]  += e;
    output[2 * i - 8]  += d;
    output[2 * i - 7]  += c;
    output[2 * i - 6]  += b;
    output[2 * i - 5]  += a;

    if (i + 1 < findex + 15) {
        const float t2 = temp[i + 1];
        const float a2 = t2 * synthesis_high[0];
        const float b2 = t2 * synthesis_high[1];
        const float c2 = t2 * synthesis_high[2];
        const float d2 = t2 * synthesis_high[3];
        const float e2 = t2 * synthesis_high[4];

        output[2 * (i + 1) - 13] += a2;
        output[2 * (i + 1) - 12] += b2;
        output[2 * (i + 1) - 11] += c2;
        output[2 * (i + 1) - 10] += d2;
        output[2 * (i + 1) - 9]  += e2;
        output[2 * (i + 1) - 8]  += d2;
        output[2 * (i + 1) - 7]  += c2;
        output[2 * (i + 1) - 6]  += b2;
        output[2 * (i + 1) - 5]  += a2;
    }
}
}
