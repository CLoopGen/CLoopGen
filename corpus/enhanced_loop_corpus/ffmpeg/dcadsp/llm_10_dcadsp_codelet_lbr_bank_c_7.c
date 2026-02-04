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
    float t1 = src[-4] * SW0;
    float t2 = src[-1] * SW3;
    float t3 = src[-3] * SW1;
    float t4 = src[-2] * SW2;
    float t5 = src[2] * SW1;
    float t6 = src[1] * SW2;
    float t7 = src[3] * SW0;
    float t8 = src[0] * SW3;
    float a = t1 - t2;
    float b = t3 - t4;
    float c = t5 + t6;
    float d = t7 + t8;
    float term1 = C1 * b;
    float term2 = C2 * c;
    float term3 = C4 * a;
    float term4 = C3 * d;
    output[i][0] = term1 - term2 + term3 - term4;
    output[i][1] = C1 * d - C2 * a - C4 * b - C3 * c;
    output[i][2] = C3 * b + C2 * d - C4 * c + C1 * a;
    output[i][3] = C3 * a - C2 * b + C4 * d - C1 * c;
}
}
