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
for (i = 0; i < len; i += 2) {
    float *src1 = input[i] + ofs;
    float a1 = src1[-4] * SW0 - src1[-1] * SW3;
    float b1 = src1[-3] * SW1 - src1[-2] * SW2;
    float c1 = src1[2] * SW1 + src1[1] * SW2;
    float d1 = src1[3] * SW0 + src1[0] * SW3;
    output[i][0] = C1 * b1 - C2 * c1 + C4 * a1 - C3 * d1;
    output[i][1] = C1 * d1 - C2 * a1 - C4 * b1 - C3 * c1;
    output[i][2] = C3 * b1 + C2 * d1 - C4 * c1 + C1 * a1;
    output[i][3] = C3 * a1 - C2 * b1 + C4 * d1 - C1 * c1;

    if (i + 1 < len) {
        float *src2 = input[i+1] + ofs;
        float a2 = src2[-4] * SW0 - src2[-1] * SW3;
        float b2 = src2[-3] * SW1 - src2[-2] * SW2;
        float c2 = src2[2] * SW1 + src2[1] * SW2;
        float d2 = src2[3] * SW0 + src2[0] * SW3;
        output[i+1][0] = C1 * b2 - C2 * c2 + C4 * a2 - C3 * d2;
        output[i+1][1] = C1 * d2 - C2 * a2 - C4 * b2 - C3 * c2;
        output[i+1][2] = C3 * b2 + C2 * d2 - C4 * c2 + C1 * a2;
        output[i+1][3] = C3 * a2 - C2 * b2 + C4 * d2 - C1 * c2;
    }
}
}
