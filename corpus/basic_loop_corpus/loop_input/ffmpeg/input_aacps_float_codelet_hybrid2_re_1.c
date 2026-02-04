#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float INTFLOAT;
typedef float INT64FLOAT;

#define LEN 65536

INTFLOAT input_data[LEN][2];
INTFLOAT output_data[2][LEN][2];
INTFLOAT filter[8];

int len = LEN;
int reverse = 0;
int i;
int j;

INTFLOAT (*in)[2] = input_data;
INTFLOAT (*out)[32][2] = (INTFLOAT(*)[32][2])output_data;

void init_vars() {
    for (int idx = 0; idx < 8; idx++) {
        filter[idx] = (INTFLOAT)(0.1f * idx);
    }
    for (int idx = 0; idx < LEN; idx++) {
        input_data[idx][0] = (INTFLOAT)idx * 0.01f;
        input_data[idx][1] = (INTFLOAT)idx * 0.02f;
    }
    for (int r = 0; r < 2; r++) {
        for (int idx = 0; idx < LEN; idx++) {
            output_data[r][idx][0] = 0.0f;
            output_data[r][idx][1] = 0.0f;
        }
    }
}