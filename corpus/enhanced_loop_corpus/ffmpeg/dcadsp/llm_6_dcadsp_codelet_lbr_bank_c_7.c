#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float output[32][4];
extern float **input;
extern ptrdiff_t ofs;
extern ptrdiff_t len;
extern float SW0;
extern float SW1;
extern float SW2;
extern float SW3;
extern float C1;
extern float C2;
extern float C3;
extern float C4;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    float *src = input[i] + ofs;
    if (src == NULL) break;
    float a = src[-4] * SW0 - src[-1] * SW3;
    float b = src[-3] * SW1 - src[-2] * SW2;
    float c = src[2] * SW1 + src[1] * SW2;
    float d = src[3] * SW0 + src[0] * SW3;
    float temp1 = C1 * b - C2 * c;
    float temp2 = C4 * a - C3 * d;
    output[i][0] = temp1 + temp2;
    output[i][1] = (C1 * d - C2 * a) - (C4 * b + C3 * c);
    if (output[i][1] < 0.0f) {
        output[i][2] = C3 * b + C2 * d - C4 * c + C1 * a;
        output[i][3] = C3 * a - C2 * b + C4 * d - C1 * c;
    } else {
        output[i][2] = C1 * a + C3 * b;
        output[i][3] = C4 * d - C1 * c;
    }
}
}
