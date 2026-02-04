#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AMRFixed {
    int n;
    int x[10];
    float y[10];
    int no_repeat_mask;
    int pitch_lag;
    float pitch_fac;
} AMRFixed;

float *out;
AMRFixed *pulses;
float *shape;
int length;
int i;
int j;

void init_vars() {
    length = 1 << 20; // 1 million elements, approx 4MB for float arrays

    out = (float*)calloc(length, sizeof(float));
    shape = (float*)malloc(length * sizeof(float));

    pulses = (AMRFixed*)malloc(sizeof(AMRFixed));
    pulses->n = 10;

    for (int idx = 0; idx < 10; idx++) {
        pulses->x[idx] = idx * 1000; // Ensure x[i] values are increasing and within bounds
        pulses->y[idx] = 1.0f + idx * 0.1f;
    }

    for (int idx = 0; idx < length; idx++) {
        shape[idx] = 1.0f + (idx % 100) * 0.01f;
    }

    pulses->no_repeat_mask = 0;
    pulses->pitch_lag = 0;
    pulses->pitch_fac = 0.0f;
}