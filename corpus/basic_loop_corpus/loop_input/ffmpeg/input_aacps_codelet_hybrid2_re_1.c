#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float INTFLOAT;
typedef float INT64FLOAT;

INTFLOAT in_data[13][2];
INTFLOAT out_data[2][8388608][2];
INTFLOAT filter[8];

INTFLOAT (*in)[2] = in_data + 6;
INTFLOAT (*out)[32][2] = (INTFLOAT(*)[32][2])out_data;
int len = 8388608;
int reverse = 0;
int i = 0;
int j = 0;

void init_vars() {
    for (int idx = 0; idx < 13; idx++) {
        in_data[idx][0] = (INTFLOAT)(idx * 1.5f);
        in_data[idx][1] = (INTFLOAT)(idx * 0.75f);
    }
    for (int idx = 0; idx < 8; idx++) {
        filter[idx] = (INTFLOAT)(1.0f / (idx + 1));
    }
    for (int r = 0; r < 2; r++) {
        for (int idx = 0; idx < 8388608; idx++) {
            out_data[r][idx][0] = 0.0f;
            out_data[r][idx][1] = 0.0f;
        }
    }
}