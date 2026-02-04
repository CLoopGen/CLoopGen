#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct EqParameter {
    float lower;
    float upper;
    float gain;
} EqParameter;

#define ARRAY_SIZE 18

float bands[ARRAY_SIZE];
float *bc;
EqParameter *param;
float fs;
int i;

void init_vars() {
    fs = 48000.0f;
    for (int j = 0; j < ARRAY_SIZE; j++) {
        bands[j] = 50.0f * (j + 1);
    }

    bc = (float*)aligned_alloc(32, ARRAY_SIZE * sizeof(float));
    param = (EqParameter*)aligned_alloc(32, ARRAY_SIZE * sizeof(EqParameter));

    for (int j = 0; j < ARRAY_SIZE; j++) {
        bc[j] = 1.0f + (j * 0.1f);
        param[j].lower = 0.0f;
        param[j].upper = 0.0f;
        param[j].gain = 0.0f;
    }
}