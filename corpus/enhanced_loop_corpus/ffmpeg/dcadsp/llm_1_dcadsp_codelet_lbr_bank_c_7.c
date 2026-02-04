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
        for (int j = 0; j < 2 && (i + j) < len; j++) {
            int idx = i + j;
            float *src = input[idx] + ofs;
            float a = src[-4] * SW0 - src[-1] * SW3;
            float b = src[-3] * SW1 - src[-2] * SW2;
            float c = src[2] * SW1 + src[1] * SW2;
            float d = src[3] * SW0 + src[0] * SW3;
            output[idx][0] = C1 * b - C2 * c + C4 * a - C3 * d;
            output[idx][1] = C1 * d - C2 * a - C4 * b - C3 * c;
            output[idx][2] = C3 * b + C2 * d - C4 * c + C1 * a;
            output[idx][3] = C3 * a - C2 * b + C4 * d - C1 * c;
        }
    }
}
