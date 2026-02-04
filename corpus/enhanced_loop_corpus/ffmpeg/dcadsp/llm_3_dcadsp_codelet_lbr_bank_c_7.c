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
    float *src0 = input[i] + ofs;
    float *src1 = (i + 1 < len) ? input[i + 1] + ofs : src0;
    float a0 = src0[-4] * SW0 - src0[-1] * SW3;
    float b0 = src0[-3] * SW1 - src0[-2] * SW2;
    float c0 = src0[2] * SW1 + src0[1] * SW2;
    float d0 = src0[3] * SW0 + src0[0] * SW3;
    float a1 = src1[-4] * SW0 - src1[-1] * SW3;
    float b1 = src1[-3] * SW1 - src1[-2] * SW2;
    float c1 = src1[2] * SW1 + src1[1] * SW2;
    float d1 = src1[3] * SW0 + src1[0] * SW3;
    output[i][0] = C1 * b0 - C2 * c0 + C4 * a0 - C3 * d0;
    output[i][1] = C1 * d0 - C2 * a0 - C4 * b0 - C3 * c0;
    output[i][2] = C3 * b0 + C2 * d0 - C4 * c0 + C1 * a0;
    output[i][3] = C3 * a0 - C2 * b0 + C4 * d0 - C1 * c0;
    if (i + 1 < len) {
        output[i + 1][0] = C1 * b1 - C2 * c1 + C4 * a1 - C3 * d1;
        output[i + 1][1] = C1 * d1 - C2 * a1 - C4 * b1 - C3 * c1;
        output[i + 1][2] = C3 * b1 + C2 * d1 - C4 * c1 + C1 * a1;
        output[i + 1][3] = C3 * a1 - C2 * b1 + C4 * d1 - C1 * c1;
    }
}
}
